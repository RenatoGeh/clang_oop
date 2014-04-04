#include <stdio.h>

typedef struct _foo Foo; 
struct _foo {
	int n;
} wat;

wat.n = 5;

int main() {
	Foo foo;
	foo.n = 10;
	printf("%d\n", wat.n);
	return 0;
}