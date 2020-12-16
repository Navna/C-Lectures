#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#include <Windows.h>

#include "image.h"

bool save(const char* path, HDC h) {
    HBITMAP hbitmap = GetCurrentObject(h, OBJ_BITMAP);
    if (hbitmap == NULL)
        return false;

    BITMAP bitmap = { 0 };
    if (GetObjectW(hbitmap, sizeof(BITMAP), &bitmap) == 0)
        return false;

    const size_t height = (size_t)bitmap.bmHeight;
    const size_t width = (size_t)bitmap.bmWidth;

    struct image* image = img_create(height, width);
    if (image == NULL) {
        return false;
    }

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            COLORREF color = GetPixel(h, (int)j, (int)i);
            struct color c = { GetRValue(color), GetGValue(color), GetBValue(color) };
            img_set_pixel(image, i, j, c);
        }
    }

    bool r = img_save(path, image);
    img_free(image);
    return r;
}

void draw(HDC h) {
    SetPixel(h, 100, 100, RGB(255, 255, 255));

    HPEN hpen = CreatePen(PS_SOLID, 1, RGB(255, 128, 192));
    if (hpen != NULL) {
        HGDIOBJ hprevpen = SelectObject(h, hpen);
        COLORREF hprevcolor = SetBkColor(h, RGB(0, 0, 0));

        POINT line[] = { {0, 50}, {100, 50}, {0, 200} };
        Polyline(h, line, sizeof(line) / sizeof(*line));

        SetBkColor(h, hprevcolor);
        SelectObject(h, hprevpen);
        DeleteObject(hpen);
    }

    HBRUSH hbrush = CreateSolidBrush(RGB(255, 255, 0));
    if (hbrush != NULL) {
        HGDIOBJ hprevbrush = SelectObject(h, hbrush);

        Pie(h, 150, 75, 250, 125, 200, 200, 400, 200);

        SelectObject(h, hprevbrush);
        DeleteObject(hbrush);
    }

    HFONT hfont = CreateFontW(0, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, NULL);
    if (hfont != NULL) {
        HGDIOBJ hprevfont = SelectObject(h, hfont);
        COLORREF hprevbgcolor = SetBkColor(h, RGB(0, 0, 0));
        COLORREF hprevfgcolor = SetTextColor(h, RGB(0, 0, 255));

        const wchar_t* const text = L"Привет!";
        TextOutW(h, 150, 50, text, (int)_tcslen(text));

        SetBkColor(h, hprevbgcolor);
        SetTextColor(h, hprevfgcolor);
        SelectObject(h, hprevfont);
        DeleteObject(hfont);
    }
}

int main(void) {
    const int width = 400;
    const int height = 200;

    HDC hdc = CreateDCW(L"DISPLAY", NULL, NULL, NULL);
    if (hdc == NULL)
        return EXIT_FAILURE;

    HDC hmc = CreateCompatibleDC(hdc);
    if (hmc == NULL) {
        DeleteDC(hdc);
        return EXIT_FAILURE;
    }

    HBITMAP hbitmap = CreateCompatibleBitmap(hdc, width, height);
    HGDIOBJ hprevbitmap = SelectObject(hmc, hbitmap);

    draw(hmc);
    save("output.bmp", hmc);

    // Восстанавливаем оригинальное состояние контекста
    SelectObject(hmc, hprevbitmap);

    // Очищаем память
    DeleteObject(hbitmap);
    DeleteDC(hmc);
    DeleteDC(hdc);
}
