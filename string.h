#ifndef _H_STRING
#define _H_STRING

#define DEF_INIT_LEN 4

#include "class.h"

/* A very basic String class implementation. */

class(String) {
	char* value;
	int ptr_size;
	int length;
};

constructor(String) {
	this->value = (char*) malloc(DEF_INIT_LEN*sizeof(char));
	this->length = DEF_INIT_LEN;
}

destructor(String) {
	free(this->value);
}

String* String_set(String*, char*);

String* String_concat(String*, char*);

char* String_get(String*);

String* String_resize(String*, int);

String* String_clone(String*);

#endif