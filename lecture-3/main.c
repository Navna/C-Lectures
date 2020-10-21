#include <stdio.h>
#include <stdarg.h>

int SumN(const int n, ...) {
    va_list args;
    va_start(args, n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int arg = va_arg(args, int);
        sum += arg;
    }
    va_end(args);
    return sum;
}

int SumUntilZero(const int n, ...) {
    int sum = 0;

    va_list args;
    va_start(args, n);
    int last = n;
    while (last != 0) {
        sum += last;
        last = va_arg(args, int);
    }
    va_end(args);

    return sum;
}

int main(void) {
    const int r1 = SumN(5, 1, -1, 1, -1, 13);
    const int r2 = SumUntilZero(1, -1, 1, -1, 13, 0);
    printf("%d %d", r1, r2);
}
