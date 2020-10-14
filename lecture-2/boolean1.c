#include <stdbool.h>
#include <stdio.h>

bool IsPositive(const int number) {
    return number > 0;
}

int main(void) {
    int a = 0;
    scanf("%i", &a);

    const bool isPositive = IsPositive(a);
    printf("%d", isPositive);
}
