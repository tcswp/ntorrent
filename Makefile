CC=gcc
TARGET=bitleech
CFLAGS=-Wall -ggdb #-DDBG
LDFLAGS=-lm -lssl -lcrypto
OBJS=bdecode.o tracker.o queue.o file.o peer.o main.o base64.o

default: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(TARGET)

bdecode.o: bdecode.c tracker.c #decode_peers()
	$(CC) $(CFLAGS) -c bdecode.c
tracker.o: tracker.c peer.c
	$(CC) $(CFLAGS) -c tracker.c
file.o: file.c
	$(CC) $(CFLAGS) -c file.c
peer.o: peer.c
	$(CC) $(CFLAGS) -c peer.c
queue.o: queue.c
	$(CC) $(CFLAGS) -c queue.c
main.o: main.c file.c
	$(CC) $(CFLAGS) -c main.c
base64.o: base64.c
	$(CC) $(CFLAGS) -c base64.c
	
clean:
	-@rm *.o $(TARGET) *~
