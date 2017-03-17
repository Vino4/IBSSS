SERVER_NODE_OBJECTS = server.o ibsss_server_node.o ibsss_session_token.o ibsss_stream_handler.o ibsss_error.o ibsss_mutex.o ibsss_op_codes.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)
server_node_dir =
spec_dir = ../specifications/
SERVER_NODE_LIBRARIES = -lpthread -lopencv_highgui -lopencv_core -lopencv_imgproc -lopencv_objdetect
server_node_inc = -I../specifications
EXECUTABLES = Server

IBSSS : $(EXECUTABLES)

Server: $(SERVER_NODE_OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@ $(SERVER_NODE_LIBRARIES) 

server.o : ibsss_server_node.o  
	$(CC) $(CFLAGS) $(server_node_inc) $(addprefix $(server_node_dir), $(basename $@).cc)

ibsss_server_node.o : ibsss_stream_handler.o
	$(CC) $(CFLAGS) $(server_node_inc) $(addprefix $(server_node_dir), $(basename $@).cc)

ibsss_stream_handler.o :
	$(CC) $(CFLAGS) $(server_node_inc) $(addprefix $(server_node_dir), $(basename $@).cc)

ibsss_op_codes.o :
	$(CC) $(CFLAGS) $(addprefix $(spec_dir), $(basename $@).cc)

ibsss_session_token.o :
	$(CC) $(CFLAGS) $(addprefix $(spec_dir), $(basename $@).c)

ibsss_mutex.o :
	$(CC) $(CFLAGS) $(addprefix $(spec_dir), $(basename $@).cc)

ibsss_error.o :
	$(CC) $(CFLAGS) $(addprefix $(spec_dir), $(basename $@).cc)

clean:
	-@rm *.o *~ $(EXECUTABLES) 2> /dev/null || true
