#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "empty block with catch+throw\n");

	try {
		catch {
			printf("NOPE\n");
			throw;
		}
	} endtry;

	printf("after\n");

	return 0;
}
