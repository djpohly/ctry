#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "error with catch+return\n");

	try {
		return 3;
	catch 3:
		printf("caught\n");
		return 0;
	} endtry;

	printf("NOPE\n");

	return 0;
}
