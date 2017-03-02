/* 
IBSSS Database Handler 

This file defines the ibsss database handler class and functionlity

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn 
*/

#include "ibsss_server.hh"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sqlite3.h> 
#include <ibsss_database.h> 
#include <algorithm>
#include <ibsss_error.hh>
#include "ibsss_database_handler.hh"
		
/*
Database_Handle::hash()

Hash the data with std::hash using hash_function

Arguments:
	std::string data
Returns:
	size_t hashed data
*/
size_t Database_Handle::hash(const std::string& data){
	return hash_function(data);
}

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
Database_Handle::Database_Handle(){

	if(sqlite3_open(IBSSS_DATABASE_FILE_PATH, &database)){
		sqlite3_close(database);
		ibsssError("failed to establish database connection");
	}	
}

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
void Database_Handle::configure(){

	if(sqlite3_threadsafe() != 1)
		ibsssError("SQLite library must be compiled with multithreading support enabled");
	
	const char * table_statement= "CREATE TABLE IF NOT EXISTS USERS("  
						"ID 			INTEGER PRIMARY KEY		  ," 
						"USERNAME		TEXT				NOT NULL," 
						"PASSWORD		TEXT				NOT NULL," 
						"EMAIL		TEXT				NOT NULL,"
						"IS_ADMIN		INTEGER			DEFAULT 0,"
						"UNIQUE(USERNAME, EMAIL));";
//	std::cout << "STATEMENT: " << table_statement << std::endl;
	if (sqlite3_exec(database, table_statement, NULL, NULL, &exec_error) != SQLITE_OK)
		std::cout << "EXEC_ERROR: " << exec_error << std::endl;
	const char * root_statement = "INSERT OR IGNORE INTO USERS"
						"(USERNAME, PASSWORD, EMAIL, IS_ADMIN) "
						"VALUES"
						"('root', 'admin', 'admin@localhost', 1)"; 
	if (sqlite3_exec(database, root_statement, NULL, NULL, &exec_error) != SQLITE_OK)
		std::cout << "EXEC_ERROR: " << exec_error << std::endl;
}

/*
Database_Handle::close()
	- Closes database connection
	- Deletes database handle from memory

Arguments:
	none
Returns:
	none
*/
void Database_Handle::close(){
	sqlite3_close(database);
}

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
int Database_Handle::createUser(std::string username, std::string password, std::string email){

	std::string create_user_statement = "INSERT INTO USERS(USERNAME, PASSWORD, EMAIL) VALUES(lower('"
								+username
								+"'), lower('"
								+std::to_string(hash(password))
								+"'), lower('"
								+email
								+"'))"; 

	if (sqlite3_exec(database, create_user_statement.c_str(), NULL, NULL, &exec_error) != SQLITE_OK){
		std::cout << "DATABASE ERROR: FAILED TO CREATE USER - " << exec_error << std::endl;
		return 0;
	}
	return 1;
}

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
int Database_Handle::authenticateUser(std::string username, std::string password){
	
	char authenticated;
	std::string authentication_statement = "SELECT EXISTS (SELECT 1 FROM USERS WHERE username = lower('"
								+username
								+"') AND password = lower('"
								+password
								//+std::to_string(hash(password))
								+"'))"; 

	if (
		sqlite3_exec
			(
					database, 
					authentication_statement.c_str(),
					[]	
						(
							void * result, 
							int number_of_columns, 
							char **columns, 
							char **column_names
						) 
					-> int
						{
							memcpy(result, columns[0], 1);
							return 0;
						}
					, 
					&authenticated, 
					&exec_error
			) 
		!= SQLITE_OK
	)
	{
		std::cout << "DATABASE ERROR: FAILED AUTHENTICATE USER - " << exec_error << std::endl;
		return 0;
	}

	return atoi(&authenticated);
}

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
int Database_Handle::changePassword(std::string username, std::string old_password, std::string new_password){

	std::string update_statement = "UPDATE users SET password = lower('" 
								+new_password
								+"') WHERE username = lower('"
								+username
								+"') AND password = lower('"
								+old_password
								+"')"; 

	if (
		sqlite3_exec
			(
					database, 
					update_statement.c_str(),
					NULL, 
					NULL, 
					&exec_error
			) 
		!= SQLITE_OK
	)
	{
		std::cout << "DATABASE ERROR: FAILED CHANGE PASSWORD - " << exec_error << std::endl;
		return 0;
	}

	if (!sqlite3_changes(database))
		return 0;

	return 1;
}

/*
Database_Handle::resetPassword()

- create a new temporary password for user	
- send new password to email
*username should always be compared in lower_case
**email should always be compared in lower_case
***temp password should be stored hashed with Database_Handle::hash() 


Arguments:
	- std::string username
	- std::string email 
Returns:
	int status
		1: success
		0: failure username already in use	
*/
int Database_Handle::resetPassword(std::string username, std::string email){

	/*TODO:	- Create New Random Password
			- Send New password to user's email
			- Store New password hashed to database
	*/
	return 0;
}

