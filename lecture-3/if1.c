#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0;
    if (scanf("%d", &n) != 1)
        return EXIT_FAILURE;

    if (n > 0)
        n += 1;

    printf("%d", n);
}
