/*
IBSSS Mutex 
This file defines the mutexes used in IBSSS 

Authors:
Matt Almenshad | Andrew Gao | Jenny Horn
*/

#include "ibsss_mutex.hh"
#include <stdio.h>
#include <stdlib.h>
#include <mutex>

std::mutex IBSSS_KILL_SESSION_MUTEX;
