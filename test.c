#include <stdio.h>
#include "string.h"
#include "vector.h"

int main(int argc, char* args[]) {
	Vector* v = new(Vector);
	String* str;
	int i;
	char* rep;

	Vector_set(v, 10, 20);
	str = Vector_toString(v);

	rep = String_get(str);

	putchar('_');
	for(i=0;rep[i]!='\0';++i)
		putchar(rep[i]);
	putchar('_');
	putchar('\n');

	delete(Vector, v);
	delete(String, str);

	return 0;
}