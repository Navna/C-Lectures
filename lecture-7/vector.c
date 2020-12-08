#include "vector.h"

#include <stdio.h>
#include <stdlib.h>



// =============
// MEMORY VECTOR
// =============

static void* vector_memory_create(const size_t n) {
    void* const context = calloc(sizeof(size_t) + n * sizeof(int), 1);
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
    struct vector_handlers* handlers;
};

struct vector* vector_create_custom(void* context, struct vector_handlers* handlers) {
    struct vector* v = calloc(1, sizeof(struct vector));
    if (v == NULL)
        return NULL;
    v->context = context;
    v->handlers = handlers;
    return v;
}

struct vector* vector_create_memory(size_t n) {
    static struct vector_handlers memory_handlers = {
        vector_memory_get_size,
        vector_memory_get_item,
        vector_memory_set_item,
        vector_memory_free
    };

    struct vector* v = calloc(1, sizeof(struct vector));
    if (v == NULL)
        return NULL;
    v->context = vector_memory_create(n);
    if (v->context == NULL)
    {
        free(v);
        return NULL;
    }
    v->handlers = &memory_handlers;
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
    return v->handlers->get_size_f(v->context);
}

int vector_get_item(struct vector* v, size_t index) {
    return v->handlers->get_item_f(v->context, index);
}

void vector_set_item(struct vector* v, size_t index, int value) {
    v->handlers->set_item_f(v->context, index, value);
}

void vector_free(struct vector* v) {
    v->handlers->free_f(v->context);
    v->context = NULL;
    v->handlers = NULL;
    free(v);
}

void vector_print(struct vector* v) {
    printf("[");

    if (v != NULL) {
        const size_t n = vector_get_size(v);
        for (size_t i = 0; i < n; ++i) {
            if (i != 0) {
                printf(", ");
            }
            printf("%d", vector_get_item(v, i));
        }
    }

    printf("]\n");
}
