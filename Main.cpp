#include "Client.h"
#include <thread>
#include <functional>



int main(int argc, char* argv[]) {
    Client client;
    client.makeConnection();
    system("pause");
    return 0;
}