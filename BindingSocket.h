#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>
#include "SimpleSocket.h"
#include <WinSock2.h>

namespace HDE
{
	class BindingSocket: public SimpleSocket
	{

	private:
		int binding;

		void connect_to_network(int sock, struct sockaddr_in address);
	public:
		BindingSocket(int domain, int service, int protocol, int port, u_long iface);
	
		int get_binding();
	};
}

#endif // !BindingSocket_hpp