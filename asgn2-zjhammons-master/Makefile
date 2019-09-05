CC=gcc
FLAGS=-Wall

wash: wash.o
	$(CC) $(FLAGS) wash.o -o wash

wash.o: wash.c
	$(CC) $(FLAGS) -c wash.c

clean:
	rm *o wash
