#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "error with catch+throw\n");

	try {
		return 3;
		catch {
			printf("caught\n");
			throw;
		}
	} endtry;

	printf("NOPE\n");

	return 0;
}
