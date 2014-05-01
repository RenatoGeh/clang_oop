#ifndef _VECTOR_H
#define _VECTOR_H

#include "class.h"
#include "string.h"

class(Vector) {
	double x;
	double y;
};

Vector* Vector_set(Vector*, double, double);

Vector* Vector_add(Vector*, double, double);

Vector* Vector_mult(Vector*, double, double);

Vector* Vector_normalize(Vector*);

Vector* Vector_clone(Vector*);

String* Vector_toString(Vector*);

#endif