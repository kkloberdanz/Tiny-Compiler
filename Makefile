CC = gcc

CFLAGS = -O2

OBJS = main.o scan.o

tiny: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o tiny

main.o: main.c headers/globals.h headers/scan.h
	$(CC) $(CFLAGS) -c main.c

scan.o: scan.c headers/scan.h headers/globals.h
	$(CC) $(CFLAGS) -c scan.c

clean:
	-rm tiny
	-rm $(OBJS)
