CC = gcc
CFLAGS = -ansi -pedantic -Wall -O2
DEBUG = -ansi -pedantic -Wall -g

test: class.o test.o
	$(CC) $? -o $@ $(CFLAGS)	

debug: class.o test.o
	$(CC) $? -o $@ $(DEBUG)

test.o: class.h

class.o: class.h

.PHONY = clean
clean:
	del *.exe
	del *.o