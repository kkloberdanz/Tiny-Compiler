CC = gcc

CFLAGS = -Og

OBJS = main.o scan.o

tiny: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o tiny

main.o: main.c globals.h scan.h
	$(CC) $(CFLAGS) -c main.c

scan.o: scan.c scan.h globals.h
	$(CC) $(CFLAGS) -c scan.c

clean:
	-rm tiny
	-rm $(OBJS)
