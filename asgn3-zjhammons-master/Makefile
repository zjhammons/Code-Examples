CC = gcc
MEMWATCH = -DMEMWATCH -DMW_STDIO
CFLAGS = -Wall -g $(MEMWATCH)

all: cardlist playerlist 

cardlist: cardmain.o cardlist.o memwatch.o
	$(CC) $(CFLAGS) -o cardlist cardmain.o cardlist.o memwatch.o

playerlist: playermain.o playerlist.o memwatch.o
	$(CC) $(CFLAGS) -o playerlist playermain.o playerlist.o memwatch.o

cardlist.o: cardlist.c cardlist.h 
	$(CC) $(CFLAGS) -c cardlist.c

playerlist.o: playerlist.c playerlist.h 
	$(CC) $(CFLAGS) -c playerlist.c

cardmain.o: cardmain.c cardlist.h 
	$(CC) $(CFLAGS) -c cardmain.c

playermain.o: playermain.c playerlist.h 
	$(CC) $(CFLAGS) -c playermain.c

memwatch.o: memwatch.c memwatch.h 
	$(CC) $(CFLAGS) -w -c memwatch.c

memwatch.c:
	ln -s /home/class_projects/memwatch-2.71/memwatch.c

memwatch.h:
	ln -s /home/class_projects/memwatch-2.71/memwatch.h

.PHONY: clean
clean:
	@-rm -f *.o cardlist playerlist

