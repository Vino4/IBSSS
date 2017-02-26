/*
IBSSS Trace 
This file defines the error handling and debugging messages settings for an ibsss server 

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn
*/

#include "ibsss_error.hh" 
#include <iostream>

void ibsssError(const char *msg){
	std::cerr << "ERROR: " << msg << std::endl;
	exit(1);
}
