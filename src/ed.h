#include <stdio.h>

typedef struct {
    char   *data;
    size_t size;     
    size_t capacity; 
} buffer;

typedef struct {
	char *fname;
	int  cursor;
	buffer *buf;
} fstate;

size_t ed(fstate *state);
void set_fname(fstate *fs, char* fname);

/* buffer */
void init_buffer(buffer *buf, size_t initial_capacity);
void append(buffer *buf, const char *data, size_t data_size);
void set(buffer *buf, const char *data, size_t data_size);

/* i/o */ 
size_t fsize(FILE *f);
size_t fbuf(FILE *f, buffer *buf);
