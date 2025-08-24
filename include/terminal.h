#pragma once

#ifdef _WIN32
#include <windows.h>

// Структура для размеров терминала
struct winsize {
    unsigned short ws_row;
    unsigned short ws_col;
};

// Функция получения размеров терминала на Windows
static int get_terminal_size(struct winsize* w) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        w->ws_col = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        w->ws_row = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        return 0;
    }
    return -1;
}

// Заглушки для других ioctl функций
#define TIOCGWINSZ 1
static int ioctl(int fd, int request, struct winsize* w) {
    if (request == TIOCGWINSZ) {
        return get_terminal_size(w);
    }
    return -1;
}

#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif