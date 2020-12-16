#include <Windows.h>

static HDC hmc;

LRESULT CALLBACK PaintProc(_In_ HWND hwindow, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam) {
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(EXIT_SUCCESS);
        return 0;


    case WM_MOUSEMOVE: {
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);
        SetPixel(hmc, x, y, RGB(0, 0, 0));
        RECT r = { x, y, x + 1, y + 1 };
        InvalidateRect(hwindow, &r, FALSE);
        UpdateWindow(hwindow);
        return 0;
    }

    case WM_PAINT:
    {
        PAINTSTRUCT ps = { 0 };
        HDC hdc = BeginPaint(hwindow, &ps);
        if (hdc != NULL) {
            const int x = ps.rcPaint.left;
            const int y = ps.rcPaint.top;
            const int w = ps.rcPaint.right - x + 1;
            const int h = ps.rcPaint.bottom - y + 1;
            BitBlt(hdc, x, y, w, h, hmc, x, y, SRCCOPY);
            EndPaint(hwindow, &ps);
        }
        return 0;
    }

    default:
        return DefWindowProcW(hwindow, message, wParam, lParam);
    }
}

int WINAPI wWinMain(_In_ HINSTANCE module, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
    const int width = 800;
    const int height = 600;
    const wchar_t paintClassName[] = L"Paint Window";

    WNDCLASSEXW paintClass = { 0 };
    paintClass.cbSize = sizeof(WNDCLASSEXW);
    paintClass.lpfnWndProc = PaintProc;
    paintClass.hInstance = module;
    paintClass.lpszClassName = paintClassName;

    if (!RegisterClassExW(&paintClass)) {
        MessageBoxW(NULL, L"Не удалось зарегистрировать класс окна!", L"Ошибка", MB_ICONERROR);
        return EXIT_FAILURE;
    }

    int x = CW_USEDEFAULT;
    int y = CW_USEDEFAULT;
    RECT screenSize = { 0 };
    if (SystemParametersInfoW(SPI_GETWORKAREA, 0, &screenSize, 0)) {
        x = (screenSize.left + screenSize.right) / 2 - width / 2;
        y = (screenSize.top + screenSize.bottom) / 2 - height / 2;
    }

    HWND hwindow = CreateWindowExW(0, paintClassName, L"Рисовалка", WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX, x, y, width, height, NULL, NULL, module, NULL);
    if (hwindow == NULL) {
        UnregisterClassW(paintClassName, module);
        MessageBoxW(NULL, L"Не удалось создать окно!", L"Ошибка", MB_ICONERROR);
        return EXIT_FAILURE;
    }

    HDC hdc = GetDC(hwindow);
    HBITMAP hbitmap = CreateCompatibleBitmap(hdc, width, height);

    hmc = CreateCompatibleDC(hdc);
    HGDIOBJ hprevbitmap = SelectObject(hmc, hbitmap);

    RECT r = { 0, 0, width, height };
    FillRect(hmc, &r, GetSysColorBrush(COLOR_WINDOW));

    ShowWindow(hwindow, nCmdShow);

    MSG msg = { 0 };
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    SelectObject(hprevbitmap, hprevbitmap);
    DeleteObject(hbitmap);
    DeleteObject(hmc);
    DeleteObject(hdc);

    return EXIT_SUCCESS;
}
