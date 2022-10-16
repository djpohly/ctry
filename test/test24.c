#include <stdio.h>
#include "try.h"

int main(void)
{
	fprintf(stderr, "nested empty blocks\n");

	try {
		try {
		} endtry;
	} endtry;

	printf("after\n");

	return 0;
}
