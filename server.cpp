#include "lib/socket.h"

int main() {
    cpp_socket::server listener;
    while (true) {
        listener.listen([](const char *str) {
            puts(str);
        });
    }
    return 0;
}
