#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "return with catch\n");

	try {
		return 0;
	} catch {
		printf("NOPE\n");
	} endtry;

	printf("NOPE\n");

	return 0;
}
