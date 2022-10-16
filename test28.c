#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "try with continue inside loop\n");

	int i;
	for (i = 0; i < 4; i++) {
		try {
			printf("%d\n", i);
			continue;
		} endtry_loop;
		printf("NOPE\n");
	}

	printf("after\n");

	return 0;
}
