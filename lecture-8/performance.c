#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void start(clock_t* t) {
    *t = clock();
}

void stop(clock_t* t) {
    clock_t current = clock();
    printf("%f\n", ((double)current - *t) / CLOCKS_PER_SEC);
}

int** create_matrix(size_t m, size_t n) {
    int** rows = calloc(m, sizeof(int*));
    if (rows == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < m; ++i) {
        rows[i] = calloc(n, sizeof(int));
        if (rows[i] == NULL) {
            for (size_t j = 0; j < i; ++j) {
                free(rows[j]);
            }
            free(rows);
            return NULL;
        }
    }
    return rows;
}

void free_matrix(int** matrix, size_t m) {
    for (size_t i = 0; i < m; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main(void) {
    clock_t t = 0;
    size_t m = 100000;
    size_t n = 1000;



    int* matrix1 = calloc(m * n, sizeof(int));
    if (matrix1 == NULL) {
        return EXIT_FAILURE;
    }

    start(&t);
    for (size_t i = 0; i < m; ++i)
        for (size_t j = 0; j < n; ++j)
            matrix1[i * n + j] += 1;
    stop(&t);

    start(&t);
    for (size_t j = 0; j < n; ++j)
        for (size_t i = 0; i < m; ++i)
            matrix1[i * n + j] += 1;
    stop(&t);

    free(matrix1);



    int** matrix2 = create_matrix(m, n);
    if (matrix2 == NULL) {
        return EXIT_FAILURE;
    }

    start(&t);
    for (size_t i = 0; i < m; ++i)
        for (size_t j = 0; j < n; ++j)
            matrix2[i][j] += 1;
    stop(&t);

    start(&t);
    for (size_t j = 0; j < n; ++j)
        for (size_t i = 0; i < m; ++i)
            matrix2[i][j] += 1;
    stop(&t);

    free(matrix2);
}
