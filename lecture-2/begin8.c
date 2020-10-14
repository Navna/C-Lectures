#include <stdio.h>

float ArithmeticMean(const float a, const float b) {
    return (a + b) / 2;
}

int main(void) {
    float a = 0;
    scanf("%f", &a);

    float b = 0;
    scanf("%f", &b);

    const float r = ArithmeticMean(a, b);
    printf("%f", r);
}
