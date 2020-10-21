#include <stdio.h>
#include <stdlib.h>

float ArithmeticMean(const float a, const float b) {
    return (a + b) / 2;
}

int main(void) {
    float a = 0;
    if (scanf("%f", &a) != 1)
        return EXIT_FAILURE;

    float b = 0;
    if (scanf("%f", &b) != 1)
        return EXIT_FAILURE;

    const float r = ArithmeticMean(a, b);
    printf("%f", r);
}
