#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "ed.h"

int main(int argc, char **argv)
{
	FILE *f;
	char *fname;

	if (argc > 1) {
		fname = argv[1];
		f = fopen(fname, "a+");
		if (f == NULL) {
			fprintf(stderr, "file error\n");
			return 1;
		}
		printf("%d\n", fcount(f));
	}

	ed(f);
}
