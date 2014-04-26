#ifndef _VECTOR_H
#define _VECTOR_H

#include "class.h"

class(Vector) {
	union {
		struct {
			double x;
			double y;
			double z;
		};
		double axis[3];
	}
};

constructor(Vector) {
	this->x = this->y = 0;
}

destructor(Vector) {}

Vector* Vector_set(Vector*, double, double);

Vector* Vector_add(Vector*, double, double);

Vector* Vector_mult(Vector*, double, double);

Vector* Vector_normalize(Vector*);

Vector* Vector_clone(Vector*);

String* Vector_toString(Vector*);

#endif