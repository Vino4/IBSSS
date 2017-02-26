/*
IBSSS OP Codes
This file defines the opcodes for the IBSSS communication protocal

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn
*/

#ifndef _IBSSS_OP_CODES_HEADER
#define _IBSSS_OP_CODES_HEADER

#include <iostream>
#include <bitset>

extern const unsigned char IBSSS_OP_HELLO;
extern const unsigned char IBSSS_OP_CREATE_USER;
extern const unsigned char IBSSS_OP_LOGIN;
extern const unsigned char IBSSS_OP_LOGOUT;
extern const unsigned char IBSSS_OP_REQUEST_STREAM_LINKS;
extern const unsigned char IBSSS_OP_REQUEST_STREAM_KEY;
extern const unsigned char IBSSS_OP_CHANGE_PASSWORD;
extern const unsigned char IBSSS_OP_FORGOT_PASSWORD;
extern const unsigned char IBSSS_OP_FORGOT_USERNAME;

void printOpCodes();

#endif /*_IBSSS_OP_CODES_HEADER*/

