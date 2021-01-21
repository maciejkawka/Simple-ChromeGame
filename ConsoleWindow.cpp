//
// Created by Maciej on 2020-04-14.
//

#include "ConsoleWindow.h"
void ConsoleWindow::setcoursor(bool visable, DWORD size) {
    if (size == 0)
        size = 20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visable;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}