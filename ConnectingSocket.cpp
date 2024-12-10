#include "ConnectingSocket.h"
#include <WinSock2.h>

HDE::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long iface) : 
	SimpleSocket(domain, service, protocol, port, iface)
{
	connect_to_network(get_sock(), get_address());
	test_connection(get_sock(), "Connecting Sock");
};

void HDE::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
	connect(sock, (struct sockaddr*)&address, sizeof(address));
}
