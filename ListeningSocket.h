#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include <stdio.h>
#include "BindingSocket.h"
#include <WinSock2.h>

namespace HDE
{
	class ListeningSocket : public BindingSocket
	{
	private:
		int backlog;
		int listening;
	public: 
		ListeningSocket(int domain, int service, int protocol, int port, u_long iface, int backlog);
		void start_listening();
	};
}

#endif // !ListeningSocket_hpp

