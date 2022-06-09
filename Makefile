CC = g++
CFLAGS = -g -Wall

default: main

main: ./src/main.o ./src/utility.o
	$(CC) $(FLAGS) -o main ./src/main.o ./src/utility.o

main.o: ./src/main.cpp ./src/include/main.h
	$(CC) $(CFLAGS) -c ./src/main.cpp

utility.o: ./src/utility.cpp ./src/include/main.h
	$(CC) $(CFLAGS) -c ./src/utility.cpp

clean:
	$(RM) main *.o *~
	