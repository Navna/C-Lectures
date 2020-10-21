#include <math.h>
#include <stdio.h>

int main(void) {
    for (float f = 0; f < 10; f += 0.1f) {
        printf("%f\n", f);
    }
    printf("\n");

    double f1 = 87654321.5;
    printf("%f\n", f1);
    f1 += 1;
    printf("%f\n", f1);
    f1 += 10;
    printf("%f\n", f1);

    const float f2 = INFINITY;
    const float f3 = NAN;
    printf("%f\n", f2);
    printf("%f\n", f3);
    printf("f2 == INFINITY: %d\n", f2 == INFINITY);
    printf("     f3 == NAN: %d\n", f3 == NAN);
    printf("     isnan(f3): %d\n", isnan(f3));
}
