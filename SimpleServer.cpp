#include "SimpleServer.h"

HDE::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long iface, int backlog)
{
	socket = new ListeningSocket(domain, service, protocol, port, iface, backlog);
}

HDE::ListeningSocket* HDE::SimpleServer::get_socket()
{
	return socket;
}