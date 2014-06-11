#include <stdio.h>
#include "class.h"
#include "string.h"
#include "vector.h"

int main(int argc, char* args[]) {
	Vector* v0 = new(Vector)(0);
	Vector* v1 = new(Vector)(1, 5.);
	Vector* v2 = new(Vector)(2, 5., 10.);
	Vector* v3 = new(Vector)(3, 5., 10., 15.);

	printf("Constructor(void) = [%.2f, %.2f, %.2f]\n", v0->x, v0->y, v0->z);
	printf("Constructor(%.2f) = [%.2f, %.2f, %.2f]\n", v1->x, v1->x, v1->y, v1->z);
	printf("Constructor(%.2f, %.2f) = [%.2f, %.2f, %.2f]\n", v2->x, v2->y, v2->x, v2->y, v2->z);
	printf("Constructor(%.2f, %.2f, %.2f) = [%.2f, %.2f, %.2f]\n", v3->x, v3->y, v3->z, v3->x, v3->y, v3->z);

	return 0;
}
