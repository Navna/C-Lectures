#include <stdio.h>

#include "image.h"

struct point {
    int x;
    int y;
};

void draw_line(struct image* image, struct color c, struct point p1, struct point p2) {
    // TODO
}

void draw_circle(struct image* image, struct color c, struct point center, int radius) {
    // TODO
}

int main(void) {
    const char* path = "output.bmp";

    // Чтение
    struct image* image = img_create(50, 50);
    printf("%zu %zu\n", img_get_height(image), img_get_width(image));

    // Изменение
    struct color orange = { 255, 127, 39 };
    img_set_pixel(image, 4, 49, orange);

    // Сохранение
    img_save(path, image);

    // Освобождение
    img_free(image);
}
