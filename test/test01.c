#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "block with return\n");

	try {
		return 0;
	} endtry;

	printf("NOPE\n");

	return 0;
}
