#ifndef CLIENT_H
#define CLIENT_H

#include <Windows.h>
#include <winsock.h>
#include <mutex>
#pragma comment(lib, "ws2_32.lib")

class Client {
private:
	static const int portNumber;
	static const char* hostAdress;
	int thisSocket;
	struct sockaddr_in socketAdress;
	int buffer[3];
	mutable std::mutex mtx;
public:
	Client();
	struct sockaddr_in createSocket();
	void makeConnection();
	~Client();
};

#endif 
