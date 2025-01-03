#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ed.h"

int main(int argc, char **argv)
{
	FILE *f;
	fstate *fs;
	long file_data_length;

	fs = (fstate*)malloc(sizeof(fstate));

	if (argc > 1) {
		fs->fname = argv[1];
		f = fopen(fs->fname, "rb");
		if (f == NULL) {
			fprintf(stderr, "file error\n");
			return 1;
		}

		file_data_length = fcount(f);
		init_buffer(fs->buf, file_data_length);

		printf("%ld\n", file_data_length);
		fclose(f);
	}

	return ed(fs);
}
