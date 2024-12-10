#include<iostream>
#include <WinSock2.h>

#include "ListeningSocket.h"
#include "TestServer.h"

using namespace std;

int main()
{
	WSADATA wsaData;
	cout << "Iniciando sistema de sockets" << endl;

	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (result != 0) {
		cout << "Error al inicializar sistema de sockets: " << WSAGetLastError() <<  endl;
		WSACleanup();
		return 1;
	}

	//HDE::ListeningSocket ls = HDE::ListeningSocket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10);
	
	//int error = WSAGetLastError();

	//if (error != 0) {
		//cout << "Error: " << error << endl;
	//}


	HDE::TestServer t;

	closesocket(t.get_socket()->get_sock());

	WSACleanup();

	return 0;
}