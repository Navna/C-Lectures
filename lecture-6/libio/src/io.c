#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* read_line(void) {
    size_t capacity = 4;
    size_t size = 0;

    char* buffer = (char*)malloc(capacity);
    if (buffer == NULL)
        return NULL;

    while (true) {
        int c = fgetc(stdin);
        if (c == '\n' || c == EOF)
            break;
        buffer[size] = (char)c;
        ++size;
        if (size == capacity) {
            capacity *= 2;
            char* new_buffer = (char*)realloc(buffer, capacity);
            if (new_buffer == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
    }

    buffer[size] = 0;
    return buffer;
}
