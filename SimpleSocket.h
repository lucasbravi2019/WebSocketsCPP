#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <WinSock2.h>

namespace HDE
{
	class SimpleSocket
	{ 
	private:
		int sock;
		struct sockaddr_in address;

	public:
		SimpleSocket(int domain, int service, int protocol, int port, u_long iface);
		virtual void connect_to_network(int sock, struct sockaddr_in address) = 0;
		void test_connection(int sock, const char item_name[]);
		struct sockaddr_in get_address();
		int get_sock();
	};

}

#endif // !SimpleSocket_hpp
