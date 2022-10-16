#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "error matches the first case\n");

	try {
		return 3;
	catch 3:
		printf("caught\n");
	catch 5:
		printf("NOPE\n");
	} endtry;

	printf("after\n");

	return 0;
}
