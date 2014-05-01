#include <stdio.h>
#include <string.h>
#include <math.h>

#include "vector.h"

#define PRECISION 2

/* Gambs */
#define STRINGIFY_0(a) #a
#define STRINGIFY_1(a) STRINGIFY_0(a)

#define GLUE_0(a, b) a##b
#define GLUE_1(a, b) GLUE_0(a, b)

#define glnstr(a, b, c) STRINGIFY_1(GLUE_1(a, GLUE_1(b, c)))
/* End of Gambs */

constructor(Vector) {
	this->x = this->y = 0;
}

destructor(Vector) {}

static char* ftos(double n) {
	int i, size;
	char* num;

	for(i=0,size=n;size>0;++i,size/=10);
	num = (char*) malloc((size+PRECISION+1)*sizeof(char));
	sprintf(num, glnstr(%., PRECISION, f), n);

	return num;
}

Vector* Vector_set(Vector* this, double x, double y) {
	this->x = x;
	this->y = y;
	return this;
}

Vector* Vector_add(Vector* this, double x, double y) {
	this->x += x;
	this->y += y;
	return this;
}

Vector* Vector_mult(Vector* this, double x, double y) {
	this->x *= x;
	this->y *= y;
	return this;
}

Vector* Vector_normalize(Vector* this) {
	double hip = sqrt(this->x*this->x + this->y*this->y);
	this->x /= hip;
	this->y /= hip;
	return this;
}

Vector* Vector_clone(Vector* this) {
	Vector* copy = new(Vector);
	copy->x = this->x;
	copy->y = this->y;
	return copy;
}

String* Vector_toString(Vector* this) {
	char* x_str = ftos(this->x);
	char* y_str = ftos(this->y);
	int x_str_len = strlen(x_str);
	int y_str_len = strlen(y_str);
	char* str = (char*) malloc((x_str_len+y_str_len+5)*sizeof(char));
	String* result = new(String);

	sprintf(str, "[%s, %s]", x_str, y_str);

	String_set(result, str);

	return result;
}