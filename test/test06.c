#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "empty block with catch\n");

	try {

	catch 3:
		printf("NOPE\n");
	} endtry;

	printf("after\n");

	return 0;
}
