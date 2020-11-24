#include <stdbool.h>
#include <stdio.h>

typedef bool (*predicate)(size_t);

bool is_prime(size_t n) {
    for (size_t i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_even(size_t n) {
    return (n % 2) == 0;
}

bool is_odd(size_t n) {
    return (n % 2) != 0;
}

ptrdiff_t find_first(const size_t* data, const size_t n, predicate p) {
    for (size_t i = 0; i < n; ++i) {
        if (p(data[i])) {
            return i;
        }
    }
    return -1;
}

typedef void (*progress_reporter)(int percents);

size_t process(progress_reporter reporter) {
    const size_t n = 2000000000ULL;
    size_t sum = 0;

    int previousProgress = -1;
    for (size_t i = 0; i < n; ++i) {
        sum += i;

        if (reporter != NULL) {
            int progress = (int)((i + 1.0) / (double)n * 100);
            if (progress != previousProgress) {
                reporter(progress);
                previousProgress = progress;
            }
        }
    }
    return sum;
}

void TextProgressReporter(int percents) {
    printf("\r%d%%", percents);
}

void BarProgressReporter(int percents) {
    printf("\r");
    for (size_t i = 0; i < percents / 10; ++i)
        printf("█");
    for (size_t i = 0; i < 10 - percents / 10; ++i)
        printf("░");
}

void TextBarProgressReporter(int percents) {
    BarProgressReporter(percents);
    printf(" %d%%", percents);
}

int main() {
    system("chcp 65001");

    //                      0   1   2   3   4
    const size_t data[] = { 25, 21, 15, 12, 11 };
    const size_t n = sizeof(data) / sizeof(*data);

    printf("%ti\n", find_first(data, n, is_prime));
    printf("%ti\n", find_first(data, n, is_even));
    printf("%ti\n", find_first(data, n, is_odd));

    process(TextBarProgressReporter);
}
