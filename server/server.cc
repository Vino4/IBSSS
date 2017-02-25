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
#include <ibsss_session_token.h> 

/*
Initializes a multithreaded ISBBB server
Takes a port and and address 
Returns a socket descriptor for the server
*/




class Client_Handle{
public:

	Client_Handle();
	void initClientSession(std::vector<Client_Handle> * container_reference, int descriptor);
	void setClientDescriptor(int descriptor);
	int getClientDescriptor();		
	int isActive();		
	int isEncrypted();		
	int isLoggedin();		
	void generateToken();
	std::thread * getThreadHandle();
	std::string getSessionToken();
private:
	
	std::vector<Client_Handle> * container;
	int client_descriptor;
	std::thread * thread_handle;
	std::string ID;
	std::string username;
	std::string session_token;
	int session_status;
};

/*
Handles each client connection
Takes client structure
returns none
*/
void clientManager(Client_Handle * client_handle){
	
	unsigned char message_buffer[256];
	unsigned int length = 0, client_descriptor = client_handle->getClientDescriptor();
	for (;;){	
		if (read(client_descriptor, &length, 4) < 0)
	            ibsssError("failed to read");
		
		if (read(client_descriptor, message_buffer, length) < 0)
	            ibsssError("failed to read");
		
		message_buffer[length] = '\0';		
	
		std::cout << "[" << client_handle->getSessionToken() << "]"
		<< length << " - "
		<< message_buffer
		<< std::endl;
	
		if (write(client_descriptor, "Fuck You!", 9) < 0)
	            ibsssError("failed to write");
	}
	close(client_descriptor);
}

std::string Client_Handle::getSessionToken(){
	return this->session_token;
}

std::thread * Client_Handle::getThreadHandle(){
	return thread_handle;
}

void Client_Handle::setClientDescriptor(int descriptor){
	client_descriptor = descriptor;
}

int Client_Handle::getClientDescriptor(){
	return client_descriptor;
}

Client_Handle::Client_Handle(){
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
		std::cout << "Creating a new session" << std::endl;
	session_token = "\0";
	username = "\0";
	ID = "\0";
	client_descriptor = -1;
	session_status = -1;
}

void Client_Handle::generateToken(){

	session_token.resize(IBSSS_SESSION_TOKEN_LENGTH+1, '\0');
	
	for(int i = 0; i < IBSSS_SESSION_TOKEN_LENGTH; i++)
		session_token[i] = IBSSS_SESSION_TOKEN_ALLOWED_CHARACTERS[rand()%69];

	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
		std::cout << "Created new session token: " << session_token << std::endl;

}

void Client_Handle::initClientSession(std::vector<Client_Handle> * container_reference, int descriptor){
	container = container_reference;
	client_descriptor = descriptor;
	generateToken();
	thread_handle = new std::thread(clientManager, this);
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
Manages connection to the sucket, starting a new thread to handle every new client
Takes a socked fd
Returns none
*/
void runConnectionManager(int main_socket){
	std::vector<Client_Handle> connection_vector;
	int client_descriptor;
	struct sockaddr_in client_address;
	socklen_t client_address_size;
	for (;;){
		if ((client_descriptor = accept(main_socket, (struct sockaddr *) &client_address
								, &client_address_size)) < 0)
			ibsssError("failed to accept incoming connection");
		Client_Handle new_connection = new Client_Handle;
		new_connection.initClientSession(&connection_vector, client_descriptor);	
		connection_vector.push_back(new_connection);
	      if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
	            std::cout << "Fully Initiated Session: [" << new_connection.getSessionToken() << "]" << std::endl;		
	}
	
	for(unsigned int i = 0; i < connection_vector.size(); i++){
		connection_vector[i].getThreadHandle()->join();	
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
	
	srand( time(0));
	
	runConnectionManager(main_socket);
	
	close(main_socket);
	sqlite3_close(db);

	return 0; 
}
