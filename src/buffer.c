#include <stdio.h>

/* All file and buffer handling */

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
