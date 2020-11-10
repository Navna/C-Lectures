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

void print(const int ptr[16], const size_t n) {
    printf("print sizeof = %zu\n", sizeof(ptr) / sizeof(*ptr));

    for (size_t i = 0; i < n; ++i) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

int main(void) {
    // Пример изменения адреса локальной переменной на стеке при рекурсивных вызовах
    PowerN(2, -5);
    printf("\n");

    // Пример статического массива
    int data[8] = { 7,6,5,4,3,2,1,0 };
    const size_t n = sizeof(data) / sizeof(*data);
    printf("main sizeof = %zu\n", n);
    print(data, n);
    printf("\n");

    // Демонстрация обратного порядка байтов
    long i = 11394560;
    unsigned char* ptr = (unsigned char*)&i;
    // DEC        HEX (Big-Endian)   HEX (Little-Endian)
    // 14593280   00 AD DE 00        00 DE AD 00
    printf("%02X %02X %02X %02X\n\n", ptr[0], ptr[1], ptr[2], ptr[3]);
}
