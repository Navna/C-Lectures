#include <stdio.h>

float PowerN(const float x, const int n) {
    printf("%zu\n", (size_t)&x);

    // База рекурсии
    if (n == 0)
        return 1.0;

    // Шаг рекурсии
    if (n > 0) {
        // Чётные n > 0
        if (n % 2 == 0) {
            const float r = PowerN(x, n / 2);
            return r * r;
        }
        // Нечётные n > 0
        else {
            const float r = PowerN(x, n - 1);
            return x * r;
        }
    }
    // n < 0
    else {
        const float r = PowerN(x, -n);
        return 1 / r;
    }
}

int main(void) {
    PowerN(2, -5);
}
