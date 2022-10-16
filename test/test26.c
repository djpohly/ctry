#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "try inside loop\n");

	int i;
	for (i = 0; i < 4; i++) {
		try {
			printf("%d\n", i);
		} endtry;
	}

	printf("after\n");

	return 0;
}
