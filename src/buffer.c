#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ed.h"

/* All buffer handling */

void init_buffer(buffer *buffer, size_t initial_capacity) {
    buffer->data = malloc(initial_capacity);
    if (!buffer->data) {
        fprintf(stderr, "Memory allocation failed\n");
    }
    buffer->size = 0;
    buffer->capacity = initial_capacity;
}

void free_buffer(buffer *buffer) {
    free(buffer->data);
    buffer->data = NULL;
    buffer->size = 0;
    buffer->capacity = 0;
}

void extend(buffer *buffer, size_t new_capacity) {
    char *new_data = realloc(buffer->data, new_capacity);
    if (new_data != NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
		exit(1);
    }
    buffer->data = new_data;
    buffer->capacity = new_capacity;
}

void append(buffer *buffer, const char *data, size_t data_size) {
    if (buffer->size + data_size > buffer->capacity) {
        size_t newCapacity = buffer->capacity * 2;
        if (newCapacity < buffer->size + data_size) {
            newCapacity = buffer->size + data_size;
        }
        extend(buffer, newCapacity);
    }
    memcpy(buffer->data + buffer->size, data, data_size);
    buffer->size += data_size;
}

