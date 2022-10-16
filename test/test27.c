#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "specific catch cases\n");

	try {
		return 5;
	catch_as(e):
		if (e == 5) {
			printf("caught\n");
		}
	} endtry;

	printf("after\n");

	return 0;
}
