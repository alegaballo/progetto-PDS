#pragma once
#include "Client.h"
#include "ProcessWindow.h"
#include <list>
#include <mutex>

class ClientList
{
	//FIFO QUEUE
	std::condition_variable cv_;
	std::list<Client> clients;
	mutable std::mutex lock_;
	unsigned int size_;

public:
	ClientList();
	Client& addClient(Client c);
	Client getClient();
	void notify(ProcessWindow wnd, ProcessWindow::Status s);
	void cleanup();
	unsigned int size() const;
};

