#include <stdio.h>

float power_n(const float x, const int n) {
    // База рекурсии
    if (n == 0)
        return 1.0;

    // Шаг рекурсии
    if (n > 0) {
        // Чётные n > 0
        if (n % 2 == 0) {
            const float r = power_n(x, n / 2);
            return r * r;
        }
        // Нечётные n > 0
        else {
            const float r = power_n(x, n - 1);
            return x * r;
        }
    }
    // n < 0
    else {
        const float r = power_n(x, -n);
        return 1 / r;
    }
}

int main(void) {
    printf("%f", power_n(2, 5));

    // power_n(2, 0)
    // power_n(2, 1)
    // power_n(2, 2)
    // power_n(2, 4)
    // power_n(2, 5)
    // main
}
