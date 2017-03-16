/* 
IBSSS Stream Handler Header

This file defines the ibsss stream handler specifications

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/

#ifndef _IBSSS_STREAM_HANDLER_HEADER
#define _IBSSS_STREAM_HANDLER_HEADER

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

#define ibsssConnectionDropped(statement) std::cout << statement << std::endl; break

#define ibsssReadMessage(descriptor, buffer, length, status)		\
												\
	if ((status = read(descriptor, buffer, length)) < 0)			\
		ibsssError("failed to read");						\
												\
	if (IBSSS_TRACE_READ_WRITE_STATUS)						\
		std::cout << "Read Status: " << status << std::endl;		\
												\
	if (status == 0)									\
		return;

#define ibsssWriteMessage(descriptor, buffer, length, status)		\
												\
	if ((status = write(descriptor, buffer, length)) < 0)			\
		ibsssError("failed to write");					\
												\
	if (IBSSS_TRACE_READ_WRITE_STATUS)						\
		std::cout << "Write Status: " << status << std::endl;		\
												\
	if (status == 0)									\
		return;

/*
Stream Handle classs
Used for managing each client connection
*/
class Stream_Handle{

	public:
	
		/*
		Stream_Handle()
		
		Initializes a stream handle 
		
		Arguments:
			none
		Returns:
			none
		*/
		Stream_Handle();
		
		/*
		killSession()
		**Thread Safe**
		- Closes TCP connection
		- Removes connection from connection manager
		
		Arguments:
			int descriptor;
		Returns:
			none
		*/
		void killSession();
		
		/*
		processStream()
		
		captures footage and sends it to clients, encrypted
		
		Arguments:
			none
		Returns:
			none
		*/
		void processStream(Stream_Handle * stream_handle, std::vector<int> * connections);
		
		/*
		addConnection()
		
		adds connection to descriptor	
		
		Arguments:
			int descritpor
		Returns:
			none
		*/
		void addConnection(int descritpor);

		/*
		initStreamSession()
		
		Initialize the client session by setting the appropriate session variables
		
		Arguments:
			none
		Returns:
			none
		*/
		void initStreamSession();
	
		/*
		setAESKey(std::string key)
	
		Sets the symetric encryption key	
	
		Arguments:
			- std::string key, the symetric AES key	
		Returns:
			none
		*/
		void setAESKey(std::string key);

            /*
            isStreaming()

		provides streaming status

            Arguments:
                  none
            Returns:
                  int streaming status 
            */
            int isStreaming();

	private:
		
		std::vector<int> * connections;
		std::thread * thread_handle;
		std::string AES_key;
		int secured_status;
		int streaming;
};
	
#endif /*_IBSSS_STREAM_HANDLER_HEADER*/
