#include <stdio.h>

int main(void) {
    int k = 0, n = 0;
    scanf("%d %d", &k, &n);

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
