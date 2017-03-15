/* 
IBSSS Stream Handler Header

This file defines the ibsss stream handler functions 

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/

#include "ibsss_restrictions.h"
#include "ibsss_stream_handler.hh"
#include "ibsss_op_codes.hh"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <vector>
#include <thread>
#include <ibsss_session_token.h>
#include <ibsss_mutex.hh>
#include <algorithm>
#include <ibsss_error.hh>

/*
Stream_Handle()
		
Initializes a stream handle 
		
Arguments:
	none
Returns:
	none
*/
Stream_Handle::Stream_Handle(){}
		
/*
killSession()
**Thread Safe**
- Closes TCP connection
- Removes connection from connection manager

Arguments:
	none;
Returns:
	none
*/
void Stream_Handle::killSession(int){
      IBSSS_STREAM_CONNECTION_MUTEX.lock();

      if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
            std::cout
            << "\n\n{[=-....Terminating Session....-=]}\n         Target: [" << getSessionToken() << "]"
            << std::endl;
	
	streaming = 0; 
 
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
            std::cout << "Closed Stream Processor<< std::endl;

	for (int i = 0; i < connection->size(); i++ )
      	close(connections[i]);
 
     if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
            std::cout << "Closed Connections << std::endl;

      delete this;

      if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
            std::cout << "Cleared session memorey" << std::endl;

      IBSSS_STREAM_CONNECTION_MUTEX.unlock();
}
		
/*
processStream()

captures footage and sends it to clients, encrypted
Arguments:
	Stream_Handle * stream_handle 
Returns:
	none
*/
void Stream_Handle::processStream(Stream_Handle * stream_handle, std::vector<int> * connections){
      int read_status, write_status;
	while (stream_handle.isStreaming()){ 

		//capture image

	      IBSSS_STREAM_CONNECTION_MUTEX.lock();
		for (int i = 0; i < connections->size(); i++){

		}

	      IBSSS_STREAM_CONNECTION_MUTEX.unlock();
	}
}
		
/*
addConnection()
		
adds connection to descriptor	
		
Arguments:
	int descritpor
Returns:
	none
*/
void Stream_Handle::addConnection(int descritpor){

	IBSSS_STREAM_CONNECTION_MUTEX.lock();
	
	connections->pushback(descriptor);

	IBSSS_STREAM_CONNECTION_MUTEX.unlock();

}

/*
initStreamSession()
		
Initialize the client session by setting the appropriate session variables
		
Arguments:
	none
Returns:
	none
*/
void Stream_Handle::initStreamSession(){

      int secured_status = 0;
      int streaming = 1;
	connections = new std::vector<int>();
	thread_handle = new std::thread(&Client_Handle::processStream, this, this);


}
	
/*
setAESKey(std::string key)
	
Sets the symetric encryption key	

Arguments:
	- std::string key, the symetric AES key	
Returns:
	none
*/
void Stream_Handle::setAESKey(std::string key);

/*
isStreaming()

Provides streaming status

Arguments:
	none
Returns:
      int streaming status
*/
int isStreaming(){
	return streaming;
}
