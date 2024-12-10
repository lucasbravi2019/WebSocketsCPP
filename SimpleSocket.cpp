#include "SimpleSocket.h"
#include <WinSock2.h>
#include <iostream>

using namespace std;

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long iface)
{
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(iface);
	sock = socket(domain, service, protocol);
	test_connection(sock, "Simple Socket");
}

void HDE::SimpleSocket::test_connection(int item_to_test, const char item_name[])
{
	char error_message[40] = "Failed to connect to: ";
	if (item_to_test == -1)
	{
		strcat_s(error_message, sizeof(error_message), item_name);
		perror(error_message);
		exit(EXIT_FAILURE);
	} 
	else
	{
		cout << "Connected successfully to: " << item_name << endl;
	} 
}

struct sockaddr_in HDE::SimpleSocket::get_address()
{
	return address;
}

int HDE::SimpleSocket::get_sock()
{
	return sock;
}