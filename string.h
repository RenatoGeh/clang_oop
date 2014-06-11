#ifndef _H_STRING
#define _H_STRING

#include "class.h"

/* A very basic String class implementation. */

class(String) {
	char* value;
	int ptr_size;
	int length;
};

String* String_set(String*, char*);

String* String_concat(String*, char*);

char* String_get(String*);

String* String_resize(String*, int);

String* String_clone(String*);

#endif