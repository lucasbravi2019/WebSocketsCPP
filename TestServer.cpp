#include "TestServer.h"
#include <string>

using namespace std;

HDE::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10)
{
	launch();
}

void HDE::TestServer::accepter()
{
	struct sockaddr_in address = get_socket()->get_address();
	int addrlen = sizeof(address);
	new_socket = accept(get_socket()->get_sock(), (struct sockaddr*)&address, (socklen_t *)&addrlen);
	recv(new_socket, buffer, sizeof(buffer), 0);
}

void HDE::TestServer::handler()
{
	cout << buffer << endl;
}

void HDE::TestServer::responder()
{
	const string body = "{\"id\": 1}";
	const string response =
		"HTTP/1.1 200 OK\r\n"
		"Content-Type: text/json\r\n"
		"Content-Length: " + to_string(body.length()) + "\r\n"
		"\r\n" +
		body;

	send(new_socket, response.c_str(), response.length(), 0);
	closesocket(new_socket);
}

void HDE::TestServer::launch()
{
	while (true)
	{
		cout << "==== Waiting ====" << endl;
		accepter();
		handler();
		responder();
		cout << "==== Done ====" << endl;
	}
}