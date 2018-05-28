CC = gcc
CFLAGS = -g  -Wall -ansi -pedantic
MAIN = parseline
OBJS = parseline.o getline.o
all : $(MAIN)



$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

parseline.o : parseline.c header.h
	$(CC) $(CFLAGS) -c parseline.c 

getline.o : getline.c header.h
	$(CC) $(CFLAGS) -c getline.c

clean :
	rm *.o $(MAIN) core

