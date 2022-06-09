CC = g++
CFLAGS = -g -Wall

default: main

main: main.o utility.o
	$(CC) $(FLAGS) -o main main.o utility.o

main.o: main.cpp main.h
	$(CC) $(CFLAGS) -c main.cpp

utility.o: utility.cpp main.h
	$(CC) $(CFLAGS) -c utility.cpp

clean:
	$(RM) main *.o *~