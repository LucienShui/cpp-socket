//
// Created by LucienShui on 2019-04-08.
//

#include "socket.h"

namespace cpp_socket {
    void error(const char *message) {
        perror(message);
        exit(1);
    }

    __socket_base::__socket_base(const char *addr, int port) {
        if ((fd = ::socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            error("socket error");
        }
        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(port);
        saddr.sin_addr.s_addr = inet_addr(addr);
    }

    __socket_base::~__socket_base() {
        close(fd);
    }

    server::server(int port) : __socket_base("0.0.0.0", port) {
        // bind
        if ((bfd = bind(fd, (sockaddr *) &saddr, sizeof(saddr))) < 0) {
            error("bind error");
        }
    }

    void server::listen(const std::function<void(const char *)> &fun) {
        // listen
        if ((lfd = ::listen(fd, QUEUE)) < 0) {
            error("listen error");
        }
        // accept
        if ((conn = accept(fd, (sockaddr *) &caddr, &len)) < 0) {
            error("conn error");
        }
        char buf[SIZE];
        if (read(conn, buf, SIZE) > 0) {
            fun(buf);
        }
    }

    bool client::send(const char *message) {
        if ((conn = ::connect(fd, (sockaddr *) &saddr, sizeof(saddr))) < 0) {
            return false;
        }
        write(fd, message, SIZE);
        return true;
    }
}
