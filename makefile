OBJS = main.o client.o server.o
CC = g++
FLAGS = -Wall
CFLAGS = -Wall -c

TicTacMath: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o TicTacMath

main.o: main.cc board.h
	$(CC) $(CFLAGS) main.cc

client.o: client.cc board.h
	$(CC) $(CFLAGS) client.cc

server.o: server.cc board.h
	$(CC) $(CFLAGS) server.cc

clean:
	rm *.o TicTacMath

