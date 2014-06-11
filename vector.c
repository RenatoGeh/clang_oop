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
	this->x = this->y = this->z = 0;
	if(n_args > 0) this->x = get_args(double);
	if(n_args > 1) this->y = get_args(double);
	if(n_args > 2) this->z = get_args(double);
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

Vector* Vector_set(Vector* this, double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
	return this;
}

Vector* Vector_add(Vector* this, double x, double y, double z) {
	this->x += x;
	this->y += y;
	this->z += z;
	return this;
}

Vector* Vector_mult(Vector* this, double x, double y, double z) {
	this->x *= x;
	this->y *= y;
	this->z *= z;
	return this;
}

Vector* Vector_normalize(Vector* this) {
	double norm = sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
	this->x /= norm;
	this->y /= norm;
	this->z /= norm;
	return this;
}

Vector* Vector_clone(Vector* this) {
	return new(Vector)(3, this->x, this->y, this->z);
}

String* Vector_toString(Vector* this) {
	char* x_str = ftos(this->x);
	char* y_str = ftos(this->y);
	char* z_str = ftos(this->z);
	int x_str_len = strlen(x_str);
	int y_str_len = strlen(y_str);
	int z_str_len = strlen(z_str);
	char* str = (char*) malloc((x_str_len+y_str_len+z_str_len+7)*sizeof(char));
	String* result = new(String)(0);

	sprintf(str, "[%s, %s, %s]", x_str, y_str, z_str);

	String_set(result, str);

	return result;
}