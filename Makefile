CC = gcc
CFLAGS = -Wall -g
OBJ = main.o file_utils.o thread_utils.o
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c file_utils.h thread_utils.h
	$(CC) $(CFLAGS) -c main.c

file_utils.o: file_utils.c file_utils.h
	$(CC) $(CFLAGS) -c file_utils.c

thread_utils.o: thread_utils.c thread_utils.h
	$(CC) $(CFLAGS) -c thread_utils.c

clean:
	rm -f $(OBJ) $(EXEC)
