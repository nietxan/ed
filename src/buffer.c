#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ed.h"

/* All buffer handling */

void init_buffer(buffer *buf, size_t initial_capacity)
{
    buf->data = (char*)malloc(sizeof(char) * initial_capacity);
    if (buf->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
		exit(1);
    }
    buf->size = 0;
    buf->capacity = initial_capacity;
}

void extend(buffer *buf, size_t new_capacity)
{
    char *new_data = (char*)realloc(buf->data, sizeof(char) * new_capacity);
    if (new_data == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
		exit(1);
    }
    buf->data = new_data;
    buf->capacity = new_capacity;
}

void set(buffer *buf, const char *data, size_t data_size)
{
	init_buffer(buf, data_size);
    memcpy(buf->data + buf->size, data, data_size);
    buf->size += data_size;
}

void append(buffer *buf, const char *data, size_t data_size)
{
    if (buf->size + data_size > buf->capacity) {
        size_t new_capacity = buf->capacity * 2;
        if (new_capacity < buf->size + data_size) {
            new_capacity = buf->size + data_size;
        }
        extend(buf, new_capacity);
    }
    memcpy(buf->data + buf->size, data, data_size);
    buf->size += data_size;
}

