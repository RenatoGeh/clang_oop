CFLAGS = -ansi -pedantic -Wall

test: 
	gcc test.c $(CFLAGS)

.PHONY = clean
clean:
	del *.exe
	del *.o
	del *~

