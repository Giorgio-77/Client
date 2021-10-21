#include "Client.h"
#include <cstdio>


Client::Client() {
	socketAdress = createSocket();
}

const char* Client::hostAdress = "127.0.0.1";
const int Client::portNumber = 1111;

struct sockaddr_in Client::createSocket() {
	// Initializing Winsock
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
	}
	struct sockaddr_in sock;
	sock.sin_family = AF_INET;
	sock.sin_port = htons(portNumber);
	sock.sin_addr.s_addr = inet_addr(hostAdress);
	thisSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (thisSocket < 0) {
		printf("Socket Creation FAILED!\n");
	}
	return sock;
}

void Client::makeConnection() {
	if (connect(thisSocket, (struct sockaddr*)&socketAdress, sizeof(socketAdress)) != 0) {
		printf("Socket Connection FAILED!\n");
		if (thisSocket)
			closesocket(thisSocket);
	}
	else {
		printf("Connected!\n");
	}
}

Client::~Client() {
	closesocket(thisSocket);
	WSACleanup();
}
