/* 
IBSSS Database Handler Header

This file defines the ibsss database handler specifications

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/

#ifndef _IBSSS_DATABASE_HANDLER_HEADER
#define _IBSSS_DATABASE_HANDLER_HEADER

#include "ibsss_client_handler.hh"
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
#include <sqlite3.h>
#include <ibsss_database.h>
#include <ibsss_session_token.h>
#include <ibsss_mutex.hh>
#include <algorithm>
#include <ibsss_error.hh>

/*
Client Handle classs
Used for managing each client connection
*/
class Database_Handle{

	public:
	
		/*
		Database_Handle()
		
		Create an ibsss datbase handle 
		This handle provides access to ibsss database from IBSSS_DATABASE_FILE_PATH
		SQLite threading macro must be predefined to support multithreading

		Arguments:
			none
		Returns:
			none
		*/
		Database_Handle();
			
		/*
		Database_Handle::configure()
		
		Initializes a database handle by:
			- Defines database structure if not already defined 
			- Ensures SQLite library is configured for multithreaded access
		Arguments:
			none
		Returns:
			none
		*/
		void configure();
			
		/*
		Database_Handle::hash()
	
		Hash the data with std::hash using hash_function
	
		Arguments:
			std::string data
		Returns:
			size_t hashed data
		*/
		size_t hash(const std::string& key);	
	
		/*
		Database_Handle::close()
		- Closes database connection
		- Deletes database handle from memory
		
		Arguments:
			none
		Returns:
			none
		*/
		void close();
		
		/*
		Database_Handle::createUser()

		Creates a user if it doesn't already exist
		*username should always be stored in lower_case
		**password should be stored hashed with Database_Handle::hash() 

		Arguments:
			- std::string username
			- std::string password
			- std::string email	
		Returns:
			int status
				1: success
				0: failure:
					- username\email already in use
					- username\password invalid	
		*/
		int createUser(std::string username, std::string password, std::string email);
		
		/*
		Database_Handle::authenticateUser()

		Authenticates user against database
		*username should always be compared in lower_case
		**password should be compared hashed with Database_Handle::hash() 


		Arguments:
			- std::string username
			- std::string password
		Returns:
			int status
				1: success
				0: failure username/password wrong	
		*/
		int authenticateUser(std::string username, std::string password);
		
		/*
		Database_Handle::changePassword()
		
		changes user's password	
		*compare password hashed with Database_Handle::hash()
		**stores new password hashed with Database_Handle::hash()	
		Arguments:
			- std::string username
			- std::string old_password
			- std::string new_password
		Returns:
			int status
			1: success
			0: failure authentication failed 
		*/
		int changePassword(std::string username, std::string new_password, std::string old_password);
		
		/*
		Database_Handle::changePassword()

		changes user's password	
		*username should always be compared in lower_case
		**old password should be compared hashed with Database_Handle::hash() 
		***new password should be stored hashed with Database_Handle::hash() 

		Arguments:
			- std::string username
			- std::string old_password
			- std::string new_password
		Returns:
			int status
				1: success
				0: failure authentication failed 
		*/
		int resetPassword(std::string username, std::string email);

	private:
				
		std::hash<std::string> hash_function;
		sqlite3 * database;
		char * exec_error;
};
	
#endif /*_IBSSS_DATABASE_HANDLER_HEADER*/
