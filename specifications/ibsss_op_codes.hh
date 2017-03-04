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

const unsigned char IBSSS_OP_HELLO = 0 | 1 << 0;
const unsigned char IBSSS_OP_CREATE_USER = 0 | 1 << 1;
const unsigned char IBSSS_OP_LOGIN = 0 | 1 << 2;
const unsigned char IBSSS_OP_LOGOUT = 0 | 1 << 2 | 1 << 0;
const unsigned char IBSSS_OP_REQUEST_STREAM_LINKS = 0 | 1 << 3;
const unsigned char IBSSS_OP_REQUEST_STREAM_KEY = 0 | 1 << 4;
const unsigned char IBSSS_OP_CHANGE_PASSWORD = 0 | 1 << 5;
const unsigned char IBSSS_OP_FORGOT_PASSWORD = 0 | 1 << 6;
const unsigned char IBSSS_OP_FORGOT_USERNAME = 0 | 1 << 7;
const unsigned char IBSSS_OP_SUCCESS= 0 | 1 << 0;
const unsigned char IBSSS_OP_FAILURE= 0;

void printOpCodes();

#endif /*_IBSSS_OP_CODES_HEADER*/

