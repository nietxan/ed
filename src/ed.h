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

/* buffer */
void init_buffer(buffer *buffer, size_t initial_capacity);
void free_buffer(buffer *buffer);
void extend(buffer *buffer, size_t new_capacity);
void append(buffer *buffer, const char *data, size_t data_size);

/* i/o */ 
long fcount(FILE *f);
