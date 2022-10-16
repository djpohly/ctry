#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "error matches the second case\n");

	try {
		return 3;
	catch 5:
		printf("NOPE\n");
	catch 3:
		printf("caught\n");
	} endtry;

	printf("after\n");

	return 0;
}
