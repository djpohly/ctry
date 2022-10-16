#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "empty block\n");

	try {
	} endtry;

	printf("after\n");

	return 0;
}
