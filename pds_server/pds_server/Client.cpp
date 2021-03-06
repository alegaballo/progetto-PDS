#include "stdafx.h"
#include "Client.h"
#include "global.h"
#include "protocol.pb.h"

#include <iostream>
#include <string>
#include <cstring>
#include <atlbase.h>
#include <atlconv.h>

#define MAXWAIT 600
#define BUFFSIZE 1024

bool readN(SOCKET s, char* buffer, int size); //reads exactly size bytes
bool sendN(SOCKET s, char* buffer, int size); //writes exactly size bytes

Client::~Client()
{
	if (sck != INVALID_SOCKET) {
		closeConnection();
	}
}

Client::Client(SOCKET s) :
	isClosed_(false),
	sck(s)
{ }

void Client::serve()
{
	if (this->sendProcessList()) {
		this->readMessage();
	}
	closeConnection();
}

bool Client::isClosed() const
{
	return isClosed_;
}

//friend swap function for copy&swap idiom
void swap(Client &c1, Client &c2) {
	std::swap(c1.sck, c2.sck);
	std::swap(c1.isClosed_, c2.isClosed_);
}

//movement constructor
Client::Client(Client && src)
{
	sck = INVALID_SOCKET;
	isClosed_ = true;
	swap(*this, src);
}

bool Client::sendProcessList()
{
	std::lock_guard<std::mutex> lg(cLock_); // we don't want the "daemon" and the serving thread to serve the same client at the same time
	std::cout << std::this_thread::get_id() <<" -sending process list" << std::endl;
	uint32_t size_ = 0;
	msgs::AppGotFocus * focus = new::msgs::AppGotFocus();
	msgs::AppList msg;
	msgs::Event focus_event;
	std::string s_msg;

	// Note: the `set_allocated_*` methods take ownership of the passed pointer,
	// and will `delete` them at the exit of the scope.
	focus->set_id((uint64_t)windows_list.onFocus()); //saving current onfocus window
	focus_event.set_allocated_got_focus(focus);
	auto windows = windows_list.windows();
	for (auto it = windows.begin(); it != windows.end(); it++) {
		msgs::Application* app = msg.add_apps();
		app->set_id((uint64_t) it->handle());

		std::string title = it->title();
		if (!title.empty()) {
			app->set_win_title(title);
		}

		std::string moduleFileName = it->moduleFileName();
		if (!moduleFileName.empty()) {
			app->set_name(moduleFileName);
		}

		app->set_allocated_icon(it->encodeIcon().release());
	}

	size_ = msg.ByteSize();
	size_ = htonl(size_);
	s_msg = msg.SerializeAsString();

	if (!sendN(sck, (char*)&size_, sizeof(uint32_t))) {
		std::cerr << "an error occurred while sending process list size" << std::endl;
		return false;
	}

	if (!sendN(sck, (char*)s_msg.c_str(), s_msg.size())) {
		std::cerr << "an error occurred while sending process list" << std::endl;
		return false;
	}


	//sending on focus window
	size_ = focus_event.ByteSize();
	size_ = htonl(size_);
	s_msg = focus_event.SerializeAsString();


	if (!sendN(sck, (char*)&size_, sizeof(uint32_t))) {
		std::cerr << "an error occurred while sending onfocus message size" << std::endl;
		return false;
	}

	if (!sendN(sck, (char*)s_msg.c_str(), s_msg.size())) {
		std::cerr << "an error occurred while sending onfocus data" << std::endl;
		return false;
	}
	std::cout << "-PROCESS LIST SENT" << std::endl;
	return true;
}

void Client::readMessage()
{
	//std::cout << "--reading message" << std::endl;
	uint32_t size_ = 0; // incoming message size
	msgs::KeystrokeRequest msg;
	msgs::Event response;
	std::string serialized_response;
	uint32_t size; // outgoing message size

	while (true) {
		if (!readN(sck, (char*)&size_, 4)) {
			std::cout << "failed reading size" << std::endl;
			break;
		}
		//std::cout << "---read size" << std::endl;

		size_ = ntohl(size_);
		std::cout << "keystroke request received" << std::endl;

		std::unique_ptr<char[]> buffer = std::make_unique<char[]>(size_);
		if (!readN(sck, buffer.get(), size_)) {
			std::cout << "failed reading msg" << std::endl;
			break;
		}
		std::cout << "----read message" << std::endl;
		msg.ParseFromArray(buffer.get(), size_);

		msgs::Response *rsp = new msgs::Response();
		//the input is sent only if the target window is the one on focus
		HWND target = (HWND)msg.app_id();
		if (target == windows_list.onFocus() && ProcessWindow(target).sendKeystroke(msg)) {
			rsp->set_req_id(msg.req_id());
			rsp->set_status(msgs::Response::Status::Response_Status_Success);
		}
		else {
			//setting error msg
			rsp->set_req_id(msg.req_id());
			rsp->set_status(msgs::Response::Status::Response_Status_WindowLostFocus);
		}
		response.set_allocated_response(rsp);

		size = htonl(response.ByteSize());
		serialized_response = response.SerializeAsString();

		if (!sendN(sck, (char*)&size, sizeof(u_long)))
			std::cerr << "an error occurred while sending response size" << std::endl;

		if (!sendN(sck, (char*)serialized_response.c_str(), serialized_response.size()))
			std::cerr << "an error occurred while response data" << std::endl;
	}
	//std::cout << "--MESSAGE READ" << std::endl;
}

void Client::closeConnection()
{
	if (sck!=INVALID_SOCKET) {
		closesocket(sck);
		sck = INVALID_SOCKET;
		isClosed_ = true;
		std::cout << "connection closed" << std::endl;
	}

}

void Client::sendMessage(ProcessWindow wnd, ProcessWindow::Status s)
{
	std::lock_guard<std::mutex> lg(cLock_); // we don't want the "daemon" and the serving thread to serve the same client at the same time
	msgs::Application * opened;
	msgs::AppDestroyed * closed;
	msgs::AppGotFocus * focus;
	msgs::Event event;
	std::string msg;
	uint32_t size;

	std::cout << std::this_thread::get_id() << "--sending message" << std::endl;
	// Note: the `set_allocated_*` methods take ownership of the passed pointer,
	// and will `delete` them at the exit of the scope.
	switch (s) {
	case ProcessWindow::W_OPENED: {
		opened = new msgs::Application();
		std::string title = wnd.title();
		std::string name = wnd.moduleFileName();
		if (!title.empty()) {
			opened->set_win_title(title);
		}
		if (!name.empty()) {
			opened->set_name(name);
		}
		opened->set_id((uint64_t)wnd.handle());
		opened->set_allocated_icon(wnd.encodeIcon().release());
		event.set_allocated_created(opened);
		break;
	}
	case ProcessWindow::W_CLOSED: {
		closed = new msgs::AppDestroyed();
		closed->set_id((uint64_t)wnd.handle());
		event.set_allocated_destroyed(closed);
		break;
	}
	case ProcessWindow::W_ONFOCUS: {
		focus = new msgs::AppGotFocus();
		focus->set_id((uint64_t)wnd.handle());
		event.set_allocated_got_focus(focus);
		break;
	}
	}

	size = event.ByteSize();
	msg = event.SerializeAsString();
	//std::cout << "Serialized msg size: " << size << std::endl << msg << std::endl;

	size = htonl(size);
	if (!sendN(sck, (char*)&size, sizeof(u_long))) {
		std::cerr << "an error occurred while sending message size" << std::endl;
	}

	if (!sendN(sck, (char*)msg.c_str(), msg.size())) {
		std::cerr << "an error occurred while sending data" << std::endl;
	}
	std::cout << "--MESSAGE SENT " << s << std::endl;
}


bool readN(SOCKET s, char* buffer, int size) {
	fd_set readset;
	struct timeval tv;
	int left, res;
	left = size;
	//std::cout << "-----called readN to read " << size << " byte" << std::endl;
	memset(buffer, 0, size);
	while (left > 0) {
		FD_ZERO(&readset);
		FD_SET(s, &readset);
		tv.tv_sec = MAXWAIT;
		tv.tv_usec = 0;
		res = select(0, &readset, NULL, NULL, /*&tv*/ NULL);
		if (res > 0) {
			res = recv(s, buffer, left, 0);
			if (res == 0) {//connection closed by client
				return false;
			}
			else if (res == SOCKET_ERROR) {//recv() failed;
				res = WSAGetLastError();
				if (res == WSAEWOULDBLOCK) {
					continue; //call select() again
				}
				return false;
			}
			left -= res;
			//std::cout << "\treceived " << res << " left " << left << std::endl;
			if (left != 0) {
				buffer += res;
			}
		}
		else { //socket error or timer expired
			return false;
		}
	}
	std::cout << "-----READ " << size << " byte" << std::endl;
	return true;
}


bool sendN(SOCKET s, char* buffer, int size) {

	int sent = 0;
	int left = size;
	while (sent != size && sent != SOCKET_ERROR) {
		sent = send(s, buffer, left, 0);
		buffer += sent;
		left -= sent;
	}
	if (sent == size) {
		return true;
	}
	return false;
}
