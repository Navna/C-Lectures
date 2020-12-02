#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

typedef size_t vector_get_size_f(void* context);
typedef int vector_get_item_f(void* context, size_t index);
typedef void vector_set_item_f(void* context, size_t index, int value);
typedef void vector_free_f(void* context);



// =============
// MEMORY VECTOR
// =============

static void* vector_memory_create(const size_t n) {
    void* const context = calloc(sizeof(size_t) + n * sizeof(n), 1);
    if (context == NULL)
        return NULL;
    *((size_t*)context) = n;
    return context;
}

static size_t vector_memory_get_size(void* const context) {
    return *((size_t*)context);
}

static int vector_memory_get_item(void* const context, const size_t index) {
    const unsigned char* data = (const unsigned char*)context;
    data += sizeof(size_t);
    return ((const int*)data)[index];
}

static void vector_memory_set_item(void* const context, const size_t index, const int value) {
    unsigned char* data = (unsigned char*)context;
    data += sizeof(size_t);
    ((int*)data)[index] = value;
}

static void vector_memory_free(void* context) {
    free(context);
}



// ===========
// FILE VECTOR
// ===========

static void* vector_file_create(/* ... */) {
    // TODO
    return NULL;
}

static size_t vector_file_get_size(void* const context) {
    // TODO
    (void)context;
    return 0;
}

static int vector_file_get_item(void* const context, const size_t index) {
    // TODO
    (void)context;
    (void)index;
    return 0;
}

static void vector_file_set_item(void* const context, const size_t index, const int value) {
    // TODO
    (void)context;
    (void)index;
    (void)value;
}

static void vector_file_free(void* context) {
    // TODO
    (void)context;
}



// ======
// VECTOR
// ======

struct vector {
    void* context;
    vector_get_size_f* get_size_f;
    vector_get_item_f* get_item_f;
    vector_set_item_f* set_item_f;
    vector_free_f* free_f;
};

struct vector* vector_create_memory(size_t n) {
    struct vector* v = calloc(1, sizeof(struct vector));
    if (v == NULL)
        return NULL;
    v->context = vector_memory_create(n);
    if (v->context == NULL)
    {
        free(v);
        return NULL;
    }
    v->get_size_f = vector_memory_get_size;
    v->get_item_f = vector_memory_get_item;
    v->set_item_f = vector_memory_set_item;
    v->free_f = vector_memory_free;
    return v;
}

struct vector* vector_create_file(const char* path, size_t n) {
    // TODO
    (void)path;
    (void)n;
    return NULL;
}

struct vector* vector_open_file(const char* path) {
    // TODO
    (void)path;
    return NULL;
}

size_t vector_get_size(struct vector* v) {
    return v->get_size_f(v->context);
}

int vector_get_item(struct vector* v, size_t index) {
    return v->get_item_f(v->context, index);
}

void vector_set_item(struct vector* v, size_t index, int value) {
    v->set_item_f(v->context, index, value);
}

void vector_free(struct vector* v) {
    v->free_f(v->context);
    v->context = NULL;
    v->get_size_f = NULL;
    v->get_item_f = NULL;
    v->set_item_f = NULL;
    v->free_f = NULL;
}
