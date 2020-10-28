#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void FillArray(int* const ptr, const size_t n) {
    for (size_t i = 0; i < n; ++i) {
        ptr[i] = (int)(1 + 2 * i);
    }
}

void PrintArray(const int* const ptr, const size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

int main(void) {
    size_t n = 0;
    if (1 != scanf("%zu", &n)) {
        return EXIT_FAILURE;
    }

    int* ptr = calloc(n, sizeof(int));

    PrintArray(ptr, n);
    FillArray(ptr, n);
    PrintArray(ptr, n);

    free(ptr);
}
