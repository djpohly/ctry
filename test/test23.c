#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "error with catch+throw and finally\n");

	try {
		return 3;
	catch_all:
		printf("caught\n");
		throw;
	finally:
		printf("finally\n");
	} endtry;

	printf("NOPE\n");

	return 0;
}
