//
// Created by LucienShui on 2019-04-08.
//

#ifndef SOCKET_SOCKET_H
#define SOCKET_SOCKET_H

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <functional>

namespace cpp_socket {
    void error(const char *message);;
    const int SIZE = 256, QUEUE = 10;
    struct __socket_base {
        int fd, conn{};
        sockaddr_in saddr{};
        explicit __socket_base(const char *addr, int port);
        ~__socket_base();
    };
    struct server : __socket_base {
        int bfd, lfd{};
        sockaddr_in caddr{};
        socklen_t len = sizeof(sockaddr_in);
        explicit server(int port = 4399);
        void listen(const std::function<void(const char *)> &fun);
    };
    struct client : __socket_base {
        explicit client(const char *addr = "127.0.0.1", int port = 4399) : __socket_base(addr, port) {}
        bool send(const char *message);
    };
}

#endif //SOCKET_SOCKET_H
