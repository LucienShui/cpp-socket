#include "lib/socket.h"
#include <iostream>
#include <string>

int main() {
    cpp_socket::client client;
    std::string str;
    while (std::getline(std::cin, str)) {
        puts(client.send(str.c_str()) ? "Success" : "Failed");
    }
    return 0;
}
