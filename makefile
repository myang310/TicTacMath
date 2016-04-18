OBJS = main.o play.o board.o
CC = g++
FLAGS = -Wall
CFLAGS = -Wall -c

TicTacMath: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o TicTacMath

main.o: main.cc play.h board.h
	$(CC) $(CFLAGS) main.cc

play.o: play.cc play.h board.h
	$(CC) $(CFLAGS) play.cc

board.o: board.cc board.h
	$(CC) $(CFLAGS) board.cc

clean:
	rm *.o TicTacMath

