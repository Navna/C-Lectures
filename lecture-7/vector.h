#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef size_t vector_get_size_f(void* context);
typedef int vector_get_item_f(void* context, size_t index);
typedef void vector_set_item_f(void* context, size_t index, int value);
typedef void vector_free_f(void* context);

struct vector_handlers {
    vector_get_size_f* get_size_f;
    vector_get_item_f* get_item_f;
    vector_set_item_f* set_item_f;
    vector_free_f* free_f;
};

struct vector;

struct vector* vector_create_custom(void* context, struct vector_handlers* handlers);

struct vector* vector_create_memory(size_t n);

struct vector* vector_create_file(const char* path, size_t n);

struct vector* vector_open_file(const char* path);

size_t vector_get_size(struct vector* v);

int vector_get_item(struct vector* v, size_t index);

void vector_set_item(struct vector* v, size_t index, int value);

void vector_free(struct vector* v);

void vector_print(struct vector* v);

#endif
