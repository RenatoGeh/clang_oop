#include <stdio.h>
#include "class.h"

int main(int argc, char* args[]) {
	int a = 8;	/* 00001000 */
	int b = 33;	/* 00010001 */

	while(a < b)
		a <<= 1;

	printf("%d\n", a);

	return 0;
}