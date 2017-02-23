SERVER_OBJECTS = server.o
CLIENT_OBJECTS = client.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)
server_dir = server/
client_dir = client/
SERVER_LIBRARIES = -lpthread -lsqlite3
CLIENT_LIBRARIES = 
server_inc = -Ispecifications
client_inc = -Ispecifications
EXECUTABLES = Server Client

IBSSS : $(EXECUTABLES)

Server: $(SERVER_OBJECTS)
	$(CC) $(LFLAGS) $< -o $@ $(SERVER_LIBRARIES) 

Client: $(CLIENT_OBJECTS)
	$(CC) $(LFLAGS) $< -o $@ $(CLIENT_LIBRARIES)

server.o : 
	$(CC) $(CFLAGS) $($(basename $@)_inc) $(addprefix $($(basename $@)_dir), $(basename $@).cc)

client.o : 
	$(CC) $(CFLAGS) $($(basename $@)_inc) $(addprefix $($(basename $@)_dir), $(basename $@).cc)

clean:
	-@rm *.o *~ $(EXECUTABLES) 2> /dev/null || true
