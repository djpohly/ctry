#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "error with finally\n");

	try {
		return 3;
	finally:
		printf("finally\n");
	} endtry;

	printf("NOPE\n");

	return 0;
}
