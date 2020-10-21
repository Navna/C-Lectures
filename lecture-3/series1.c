#include <stdio.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int item = 0;
        scanf("%d", &item);
        sum += item;
    }

    printf("%d", sum);
}
