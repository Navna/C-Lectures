#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int k = 0, n = 0;
    if (scanf("%d %d", &k, &n) != 2)
        return EXIT_FAILURE;

    for (int i = 0; i < n; ++i) {
        printf("%d\n", k);
    }
    printf("\n");

    {
        int i = 0;
        while (i < n) {
            printf("%d\n", k);
            ++i;
        }
    }
}
