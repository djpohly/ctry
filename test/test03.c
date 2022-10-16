#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "empty block with finally\n");

	try {

	} finally {
		printf("finally\n");
	} endtry;

	printf("after\n");

	return 0;
}
