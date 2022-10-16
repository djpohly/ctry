#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "error with catch and finally\n");

	try {
		return 3;
	catch 3:
		printf("caught\n");
	finally:
		printf("finally\n");
	} endtry;

	printf("after\n");

	return 0;
}
