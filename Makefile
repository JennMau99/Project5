CC = gcc
CFLAGS = -g  -Wall -ansi -pedantic
MAIN = parseline
OBJS = parseline.o
all : $(MAIN)



$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

parseline.o : parseline.c
	$(CC) $(CFLAGS) -c parseline.c 

clean :
	rm *.o $(MAIN) core

