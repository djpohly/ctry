#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "empty block with catch and finally\n");

	try {

	catch 3:
		printf("NOPE\n");
	finally:
		printf("finally\n");
	} endtry;

	printf("after\n");

	return 0;
}
