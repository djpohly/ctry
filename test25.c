#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "nested finally\n");

	try {
		try {
			finally {
				printf("inner\n");
			}
		} endtry;
		finally {
			printf("outer\n");
		}
	} endtry;

	printf("after\n");

	return 0;
}
