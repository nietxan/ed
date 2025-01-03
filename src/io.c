#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#include "ed.h"

size_t fsize(FILE *f)
{
	struct stat st;
	fstat(fileno(f), &st);
	return st.st_size;
}

size_t fbuf(FILE *f, buffer *buf) 
{
	size_t size = fsize(f);
	char data[size];

	fgets(data, size, f);
	set(buf, data, size);

	return size;
}

