#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_SIZE 4096

long fcount(FILE *f)
{
	struct stat st;
	fstat(fileno(f), &st);
	return st.st_size;
}

