#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "ed.h"

int main(int argc, char **argv)
{
	FILE *f;
	char *fn;

	if (argc > 1) {
		fn = argv[1];
		f = fopen(fn, "a+");
		if (f == NULL) {
			fprintf(stderr, "file error\n");
			return 1;
		}
		printf("%d\n", fcount(f));
	}

	return ed(f);
}
