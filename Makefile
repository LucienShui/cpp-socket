main: server.cpp lib/socket.cpp lib/socket.h
	@g++ lib/socket.cpp -c
	@g++ server.cpp socket.o -o server
	@g++ client.cpp socket.o -o client
	@rm socket.o
clean:
	@rm -rf client server
