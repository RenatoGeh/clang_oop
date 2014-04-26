#include <stdio.h>
#include <math.h>
#include "vector.h"

#define PRECISION 2;
#define glnstr(a, b, c) #a##b##c

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
	String* result = new(String);

	String_set(result, "[");
	String_concat(result, x_str);
	String_concat(result, ", ");
	String_concat(result, y_str);
	String_concat(result, "]");

	return result;
}