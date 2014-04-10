#include <stdio.h>
#include "class.h"

class(Base) {
	int x, y;
	char* name;
};

constructor(Base) {
	this->x = this->y = 0;
	this->name = "Base Class";
}

destructor(Base) {}

class(Derived) {
	int x, y;
	char* name;
	int n;
};

constructor(Derived) {
	this->x = 10;
	this->y = 20;
	this->name = "Derived Class";
}

destructor(Derived) {
}

int main() {
	Base* b = new(Base);
	Derived* d = new(Derived);

	printf("Base:\n(x, y) = (%d, %d)\nname = \"%s\"\nDerived:\n(x, y) = (%d, %d)\nname = \"%s\"\n", 
		b->x, b->y, b->name, d->x, d->y, d->name);

	delete(Base, b);
	delete(Derived, d);

	return 0;
}