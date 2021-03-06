#include "clientprotocol.h"
#include "protocol.pb.h"

#include <QTcpSocket>


ClientProtocol::ClientProtocol(QTcpSocket *client, QObject *parent) :
    QObject(parent),
    client_(nullptr),
    state_(Stopped),
    last_id_(0)
{
    setSocket(client);
    connect(&msgStream_, &MessageStream::messageReceived, this, &ClientProtocol::receiveMessage);
}

void ClientProtocol::setSocket(QTcpSocket *client)
{
    if (client_ == client)
        return;

    if (client_) {
        client_->disconnect(this);
        stop();
    }

    client_ = client;
    msgStream_.setDevice(client_);
    pending_reqs_.clear();

    if (client_) {
        connect(client_, &QTcpSocket::aboutToClose, this, &ClientProtocol::stop);
        connect(client_, &QTcpSocket::disconnected, this, &ClientProtocol::hardStop);

        if (client_->isOpen())
            start();
    }
}

void ClientProtocol::start()
{
    state_ = Init;
    emit started();
}

void ClientProtocol::stop()
{
    // Any operations that still need to be done right before
    // closing the socket go here.  At this stage the socket
    // is still open, although not for long.

    // The final phase of a soft stop is a hard stop
    hardStop();
}

void ClientProtocol::hardStop()
{
    if (state_ == Stopped)
        return;
    // Here the socket is to be considered already closed for any reason
    // (closed by either local or remote peer, or error)
    // It's mostly important to signal the end of the protocol
    // to any collaborator/observing objects.
    state_ = Stopped;
    emit stopped();
}

void ClientProtocol::receiveMessage(const QByteArray &msg)
{
    switch (state_) {
        case Init: {
            msgs::AppList appList;
            appList.ParseFromArray(msg.data(), msg.size());
            auto& apps = appList.apps();

            // copy the pointers to a vector and send the vector around
            std::vector<const msgs::Application*> appMsgs {apps.data(), apps.data() + apps.size()};
            emit appListReceived(appMsgs);

            state_ = AcceptingEvents;
            break;
        }

        case AcceptingEvents:  {
            msgs::Event event;
            event.ParseFromArray(msg.data(), msg.size());
            if (event.has_created())
                emit appCreated(event.created());
            if (event.has_destroyed())
                emit appDestroyed(event.destroyed().id());
            if (event.has_got_focus())
                emit appGotFocus(event.got_focus().id());
            if (event.has_response()) {
                auto iter = pending_reqs_.find(event.response().req_id());
                if (iter != pending_reqs_.end()) {
                    auto req = *iter->second;
                    pending_reqs_.erase(iter);
                    emit responseReceived(req, event.response());
                }
            }
            break;
        }
    }
}

ClientProtocol::RequestId ClientProtocol::nextId()
{
    do { last_id_++; } while(last_id_ == INVALID_REQUEST);
    return last_id_;
}

ClientProtocol::RequestId ClientProtocol::sendRequest(std::unique_ptr<msgs::KeystrokeRequest> req)
{
    qDebug() << req->DebugString().c_str();

    if (!req)
        return INVALID_REQUEST;

    auto req_id = nextId();
    req->set_req_id(req_id);

    std::string raw = req->SerializeAsString();
    msgStream_.sendMessage(raw.data(), raw.size());

    pending_reqs_.emplace(req_id, std::move(req));
    return req_id;
}
