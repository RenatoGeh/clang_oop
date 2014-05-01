#include <string.h>
#include "string.h"

constructor(String) {
	this->value = (char*) malloc(DEF_INIT_LEN*sizeof(char));
	this->length = DEF_INIT_LEN;
}

destructor(String) {
	free(this->value);
}

static bool String_autocheck(String* this, int n) {
	int m = strlen(this->value);

	if(n < this->ptr_size) return false;

	if(m < n)
		while(m < n)
			m <<= 1;
	else if(n < m/2)
		while(n < m)
			m >>= 1;

	String_resize(this, m);
	this->length = n;
	this->ptr_size = m;
	return true;
}

String* String_set(String* this, char* value) {
	String_autocheck(this, strlen(value));
	strcpy(this->value, value);
	return this;
}

String* String_concat(String* this, char* value) {
	int n = strlen(value) + strlen(this->value);
	String_autocheck(this, n);
	strcat(this->value, value);
	return this;
}

char* String_get(String* this) {
	return this->value;
}

String* String_resize(String* this, int size) {
	char* temp = (char*)malloc((size+1)*sizeof(char));
	free(this->value);
	this->value = temp;
	return this;
}

String* String_clone(String* this) {
	String* copy = new(String);
	strcpy(copy->value, this->value);
	copy->length = this->length;
	copy->ptr_size = this->ptr_size;
	return copy;
}
