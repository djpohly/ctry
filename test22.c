#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "error with catch+error and finally\n");

	try {
		return 5;

		catch {
			printf("caught\n");
			return 3;
		}
		finally {
			printf("finally\n");
		}
	} endtry;

	printf("NOPE\n");

	return 0;
}
