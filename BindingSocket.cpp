#include "BindingSocket.h"
#include <WinSock2.h>

HDE::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long iface): 
	SimpleSocket(domain, service, protocol, port, iface)
{
	connect_to_network(get_sock(), get_address());
	test_connection(get_sock(), "Binding sock");
}

void HDE::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
	binding = bind(sock, (struct sockaddr *)&address, sizeof(address));
}

int HDE::BindingSocket::get_binding()
{
	return binding;
}
