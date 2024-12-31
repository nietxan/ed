#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 4096

int fcount(FILE *f)
{
	char c;
	int count;

	for (;;) {
		c = fgetc(f);
		if (c == EOF)
			break;
		++count;
	}		

	return count;
}

char *fname(FILE *f)
{
	int fno;
	ssize_t r;
	char *filename;
	char proclnk[MAX_SIZE];

	filename = (char*)malloc(MAX_SIZE * sizeof(char));

	fno = fileno(f);
	sprintf(proclnk, "/proc/self/fd/%d", fno);
	r = readlink(proclnk, filename, MAX_SIZE);
	if (r < 0)
	{
		fprintf(stderr, "failed to readlink\n");
		return NULL;
	}
	filename[r] = '\0';

	return filename;
}
