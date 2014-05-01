CC = gcc
CFLAGS = -ansi -pedantic -Wall -O2 -lm
DEBUG = -ansi -pedantic -Wall -g -lm

test: class.o string.o vector.o test.o
	$(CC) $? -o $@ $(CFLAGS)	

debug: class.o string.o vector.o test.o
	$(CC) $? -o $@ $(DEBUG)

test.o: class.h vector.h string.h

class.o: class.h

vector.o: vector.h

string.o: string.h

.PHONY = clean
clean:
	rm *.exe
	rm *.exe
clean_win:
	del *.exe
	del *.o