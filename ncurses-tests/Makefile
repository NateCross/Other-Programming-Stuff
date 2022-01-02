CC = g++
CFLAGS = -g -Wall
LIB = -lncurses

ncurses8: ncurses8.o
	$(CC) $^ -o $@ $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) $< -c
