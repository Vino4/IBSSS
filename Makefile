OBJS = MovieList.o Movie.o NameList.o Name.o Iterator.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
SERVER_DIR = server/
CLIENT_DIR = server/
IBSSS : $(OBJS)
    $(CC) $(LFLAGS) $(OBJS) -o p1

