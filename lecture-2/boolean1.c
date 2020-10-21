#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool IsPositive(const int number) {
    return number > 0;
}

int main(void) {
    int a = 0;
    if (scanf("%i", &a) != 1)
        return EXIT_FAILURE;

    const bool isPositive = IsPositive(a);
    printf("%d", isPositive);
}
