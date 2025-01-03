#include <stdio.h>

typedef struct {
	char          *fname;
	unsigned int  cursor;
} fstate;

size_t ed(fstate *state);

int fcount(FILE *f);

char *fname(FILE *f);
