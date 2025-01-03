#include <stdlib.h>

#include "ed.h"

int main(int argc, char **argv)
{
	FILE *f;
	fstate *fs;

	fs = (fstate*)malloc(sizeof(fstate));
	fs->buf = (buffer*)malloc(sizeof(buffer));

	if (argc > 1) {
		set_fname(fs, argv[1]);
		f = fopen(fs->fname, "rb");
		if (f == NULL) {
			fprintf(stderr, "file error\n");
			return 1;
		}

		printf("%ld\n", fsize(f));
		fclose(f);
	}

	return ed(fs);
}
