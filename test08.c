#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "error 3 with catch\n");

	try {
		return 3;
		catch {
			printf("caught\n");
		}
	} endtry;

	printf("after\n");

	return 0;
}
