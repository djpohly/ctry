#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "return with catch and finally\n");

	try {
		return 0;

		catch {
			printf("NOPE\n");
		}
		finally {
			printf("finally\n");
		}
	} endtry;

	printf("NOPE\n");

	return 0;
}
