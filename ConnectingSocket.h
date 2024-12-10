#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include "SimpleSocket.h"
#include <WinSock2.h>

namespace HDE
{
	class ConnectingSocket : public SimpleSocket
	{

	public:
		ConnectingSocket(int domain, int service, int protocol, int port, u_long iface);
		void connect_to_network(int sock, struct sockaddr_in address);
	};
}



#endif // !ConnectingSocket_hpp