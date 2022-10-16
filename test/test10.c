#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "empty block with catch+error\n");

	try {
	catch:
		printf("NOPE\n");
		return 3;
	} endtry;

	printf("after\n");

	return 0;
}
