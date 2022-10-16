#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "return with catch+error\n");

	try {
		return 0;
		catch {
			printf("NOPE\n");
			return 3;
		}
	} endtry;

	printf("NOPE\n");

	return 0;
}
