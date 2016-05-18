CC = gcc

CFLAGS = -Og

OBJS = main.o scan.o util.o

tiny: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o tiny

main.o: main.c globals.h scan.h util.h
	$(CC) $(CFLAGS) -c main.c

scan.o: scan.c scan.h globals.h util.h
	$(CC) $(CFLAGS) -c scan.c

util.o: globals.h util.h
	$(CC) $(CFLAGS) -c util.c

clean:
	-rm tiny
	-rm $(OBJS)
