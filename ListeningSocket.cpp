#include "ListeningSocket.h"
#include <WinSock2.h>

HDE::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long iface, int backlog) :
	BindingSocket(domain, service, protocol, port, iface)
{
	ListeningSocket::backlog = backlog;
	start_listening();
	test_connection(listening, "Listening sock");
}

void HDE::ListeningSocket::start_listening()
{
	listening = listen(get_sock(), backlog);
}