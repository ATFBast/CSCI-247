CC = gcc
CFLAGS = -g

hello: main.o foo.o
	$(CC) $(CFLAGS) -o hello main.o foo.o

main.o: main.c foo.h
	$(CC) $(CFLAGS) -c main.c

foo.o: foo.c foo.h
	$(CC) $(CFLAGS) -c foo.c

run: hello
	./hello

clean:
	rm -f *.o hello