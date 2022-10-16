#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "specific catch cases\n");

	try {
		return 5;
	} catch {
	case 3:
		printf("NOPE\n");
		break;
	case 5:
		printf("caught\n");
		break;
	} endtry;

	printf("after\n");

	return 0;
}
