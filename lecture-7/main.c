#include <stdio.h>
#include "vector.h"

struct slice_context {
    struct vector* v;
    size_t offset;
    size_t size;
};

static size_t vector_slice_get_size(void* const context) {
    struct slice_context* c = (struct slice_context*)context;
    return c->size;
}

static int vector_slice_get_item(void* const context, const size_t index) {
    struct slice_context* c = (struct slice_context*)context;
    return vector_get_item(c->v, c->offset + index);
}

static void vector_slice_set_item(void* const context, const size_t index, const int value) {
    struct slice_context* c = (struct slice_context*)context;
    vector_set_item(c->v, c->offset + index, value);
}

static void vector_slice_free(void* context) {
    free(context);
}

struct vector* vector_slice_create(struct vector* v, size_t offset, size_t size) {
    static struct vector_handlers memory_handlers = {
        vector_slice_get_size,
        vector_slice_get_item,
        vector_slice_set_item,
        vector_slice_free
    };

    if (v == NULL || offset + size > vector_get_size(v)) {
        return NULL;
    }

    struct slice_context* context = calloc(1, sizeof(struct slice_context));
    if (context == NULL) {
        return NULL;
    }
    context->v = v;
    context->offset = offset;
    context->size = size;

    struct vector* slice_v = vector_create_custom(context, &memory_handlers);
    if (slice_v == NULL) {
        free(context);
    }

    return slice_v;
}

int main(void) {
    struct vector* const v = vector_create_memory(9);
    const size_t n = vector_get_size(v);
    for (size_t i = 0; i < n; ++i) {
        vector_set_item(v, i, (int)(2 * i + 1));
    }

    struct vector* const first_slice = vector_slice_create(v, 3, 4);
    struct vector* const second_slice = vector_slice_create(first_slice, 1, 3);

    vector_print(v);
    vector_print(first_slice);
    vector_print(second_slice);

    vector_set_item(second_slice, 1, -1);

    vector_print(v);
    vector_print(first_slice);
    vector_print(second_slice);

    vector_free(second_slice);
    vector_free(first_slice);
    vector_free(v);
}
