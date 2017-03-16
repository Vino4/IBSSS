SERVER_OBJECTS = server.o ibsss_server.o ibsss_session_token.o ibsss_client_handler.o ibsss_error.o ibsss_mutex.o ibsss_op_codes.o ibsss_database_handler.o ibsss_client_operations.o ibsss_crypto.o
CLIENT_OBJECTS = client.o ibsss_server_connection_handler.o ibsss_server_connection_operations.o ibsss_error.o ibsss_mutex.o ibsss_op_codes.o ibsss_session_token.o ibsss_cypto.o 
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)
server_dir = server/
crypto_dir = crypto/
client_dir = client/
spec_dir = specifications/
SERVER_LIBRARIES = -lpthread -lsqlite3 -lcryptopp
CRYPTO_LIBRARIES = -lcryptopp
CLIENT_LIBRARIES = 
server_inc = -Ispecifications -Icrypto
client_inc = -Ispecifications 
crypto_inc = -Ispecifications 
EXECUTABLES = Server

IBSSS : $(EXECUTABLES)

Server: $(SERVER_OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@ $(SERVER_LIBRARIES) 

Client: $(CLIENT_OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@ $(CLIENT_LIBRARIES)

server.o : ibsss_server.o  
	$(CC) $(CFLAGS) $($(basename $@)_inc) $(addprefix $($(basename $@)_dir), $(basename $@).cc)

ibsss_server.o : ibsss_client_handler.o
	$(CC) $(CFLAGS) $(server_inc) $(addprefix $(server_dir), $(basename $@).cc)

ibsss_client_handler.o :
	$(CC) $(CFLAGS) $(server_inc) $(addprefix $(server_dir), $(basename $@).cc)

ibsss_client_operations.o :
	$(CC) $(CFLAGS) $(server_inc) $(addprefix $(server_dir), $(basename $@).cc)

ibsss_database_handler.o :
	$(CC) $(CFLAGS) $(server_inc) $(addprefix $(server_dir), $(basename $@).cc)

ibsss_op_codes.o :
	$(CC) $(CFLAGS) $(addprefix $(spec_dir), $(basename $@).cc)

ibsss_session_token.o :
	$(CC) $(CFLAGS) $(addprefix $(spec_dir), $(basename $@).c)

ibsss_mutex.o :
	$(CC) $(CFLAGS) $(addprefix $(spec_dir), $(basename $@).cc)

ibsss_error.o :
	$(CC) $(CFLAGS) $(addprefix $(spec_dir), $(basename $@).cc)

ibsss_crypto.o :
		$(CC) $(CFLAGS) $(crypto_inc) $(addprefix $(crypto_dir), $(basename $@).cpp) $(CRYPTO_LIBRARIES) 

client.o : ibsss_server_connection_handler.o ibsss_server_connection_operations.o
	$(CC) $(CFLAGS) $(client_inc) $(addprefix $(client_dir), $(basename $@).cc)

ibsss_server_connection_handler.o:
	$(CC) $(CFLAGS) $(client_inc) $(addprefix $(client_dir), $(basename $@).cc)

ibsss_server_connection_operations.o:
	$(CC) $(CFLAGS) $(client_inc) $(addprefix $(client_dir), $(basename $@).cc)

clean:
	-@rm *.o *~ $(EXECUTABLES) 2> /dev/null || true
