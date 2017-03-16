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
void Stream_Handle::killSession(){
      IBSSS_STREAM_CONNECTION_MUTEX.lock();

      if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
            std::cout
            << "\n\n{[=-....Terminating Stream....-=]}\n" 
            << std::endl;
	
	streaming = 0; 
	
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
            std::cout << "Closed Stream Processor" << std::endl;

	for (unsigned int i = 0; i < connections->size(); i++ )
      	close((*(connections))[i]);
	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
            std::cout << "Closed Connections" << std::endl;

	if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_SESSIONS)
      std::cout << "Terminated Stream" << std::endl;
      
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
	while (stream_handle->isStreaming()){ 

		//capture image

	      IBSSS_STREAM_CONNECTION_MUTEX.lock();
		for (unsigned int i = 0; i < connections->size(); i++){

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
void Stream_Handle::addConnection(int descriptor){

	IBSSS_STREAM_CONNECTION_MUTEX.lock();
	
	connections->push_back(descriptor);

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

      secured_status = 0;
      streaming = 1;
	connections = new std::vector<int>();
	thread_handle = new std::thread(&Stream_Handle::processStream, this, this, connections);


}
	
/*
setAESKey(std::string key)
	
Sets the symetric encryption key	

Arguments:
	- std::string key, the symetric AES key	
Returns:
	none
*/
void Stream_Handle::setAESKey(std::string key){

      AES_key.assign(key);

      if (IBSSS_DEBUG_MESSAGES && IBSSS_TRACE_OPERATIONS)
            std::cout
            << "stream assigned key: "
            << AES_key
            << std::endl;
}

/*
isStreaming()

Provides streaming status

Arguments:
	none
Returns:
      int streaming status
*/
int Stream_Handle::isStreaming(){
	return streaming;
}
