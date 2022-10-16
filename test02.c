#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "block with error\n");

	try {
		return 3;
	} endtry;

	printf("NOPE\n");

	return 0;
}
