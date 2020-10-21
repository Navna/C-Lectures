#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0;
    if (scanf("%d", &n) != -1)
        return EXIT_FAILURE;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int item = 0;
        if (scanf("%d", &item) != -1)
            return EXIT_FAILURE;
        sum += item;
    }

    printf("%d", sum);
}
