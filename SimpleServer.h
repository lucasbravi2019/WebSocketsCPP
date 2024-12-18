#ifndef SimpleServer_hpp
#define SimpleServer_hpp

#include "ListeningSocket.h"
#include <io.h>

namespace HDE
{
	class SimpleServer
	{
	private:
		ListeningSocket *socket;
		virtual void accepter() = 0;
		virtual void handler() = 0;
		virtual void responder() = 0;

	public: 
		SimpleServer(int domain, int service, int protocol, int port, u_long iface, int backlog);
		virtual void launch() = 0;
		ListeningSocket* get_socket();

	};
}


#endif // !SimpleServer_hpp
