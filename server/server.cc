/* 
IBSSS Main Server

This server manages the following:
	- Users, streams, stream keys and access control
	- Communication protocal

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/
#include "server.hh"
#include "ibsss_op_codes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <thread>
#include <sqlite3.h> 
#include <ibsss_database.h> 

/*
Initializes a multithreaded ISBBB server
Takes a port and and address 
Returns a socket descriptor for the server
*/

class Client_Handle{
public:

	Client_Handle();
	void initClientHandle();		

private:
	int client_token;
};

Client_Handle::Client_Handle(){
	
}

int initServer(struct sockaddr_in * server_address, int main_port){

	int main_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (main_socket < 0) 
		ibsssError("could not open main socket");
	bzero((char *) server_address, sizeof(struct sockaddr_in));
	
	server_address->sin_family = AF_INET;
	server_address->sin_addr.s_addr = INADDR_ANY;
	server_address->sin_port = htons(main_port);

	if (bind(main_socket, (struct sockaddr *) server_address, sizeof(struct sockaddr_in)) < 0) 
		ibsssError("binding main address failed");

	if (listen(main_socket, IBSSS_MAXIMUM_BENDING_CONNECTIONS) < 0)
		ibsssError("listening to main socket failed");

	return main_socket;
}

/*
Handles each client connection
Takes client structure
returns none
*/
void clientManager(int client_descriptor){
	
	char message_buffer[256];
	
	if (read(client_descriptor, message_buffer, 6) < 0)
            ibsssError("failed to read");

	std::cout << message_buffer << std::endl;

	if (write(client_descriptor, "Fuck You!", 9) < 0)
            ibsssError("failed to write");
	close(client_descriptor);
}

/*
Manages connection to the sucket, starting a new thread to handle every new client
Takes a socked fd
Returns none
*/
void runConnectionManager(int main_socket){
	std::vector<std::thread> connection_vector;
	int client_descriptor;
	struct sockaddr_in client_address;
	socklen_t client_address_size;
	for (;;){
		if ((client_descriptor = accept(main_socket, (struct sockaddr *) &client_address
								, &client_address_size)) < 0)
			ibsssError("failed to accept incoming connection");
	
		connection_vector.push_back(std::thread(clientManager, client_descriptor));
	}
	
	for(unsigned int i = 0; i < connection_vector.size(); i++){
		connection_vector[i].join();	
	} 
}

int main(int argc, char *argv[]){
	
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_OPCODES)
		printOpCodes();
	

	int main_socket, main_port;
	struct sockaddr_in server_address;
	sqlite3 *db;

	main_port = IBSSS_DEFAULT_PORT;	
	if (argc >= 2)
		main_port = atoi(argv[1]);

	if(sqlite3_open(IBSSS_DATABASE_FILE_PATH, &db)){
		sqlite3_close(db);
		ibsssError("failed to establish database connection");
	}

	main_socket = initServer(&server_address, main_port);
	
	runConnectionManager(main_socket);
	
	close(main_socket);
	sqlite3_close(db);

	return 0; 
}
