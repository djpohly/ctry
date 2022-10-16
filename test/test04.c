#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "return with finally\n");

	try {
		return 0;
	} finally {
		printf("finally\n");
	} endtry;

	printf("NOPE\n");

	return 0;
}
