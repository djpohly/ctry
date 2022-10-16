#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "error with catch+error\n");

	try {
		return 5;
	catch_all:
		printf("caught\n");
		return 3;
	} endtry;

	printf("NOPE\n");

	return 0;
}
