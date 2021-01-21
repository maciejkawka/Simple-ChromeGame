#include <windows.h>

#ifndef GRACHROME_CONSOLEWINDOW_H
#define GRACHROME_CONSOLEWINDOW_H


class ConsoleWindow {

    HANDLE console;
    COORD CursorPosition;


public:
    void gotoXY(int _x, int _y){
        CursorPosition.X = _x;
        CursorPosition.Y = _y;
        SetConsoleCursorPosition(console, CursorPosition);
    }

    void setcoursor(bool visable, DWORD size);

    ConsoleWindow(){
        console = GetStdHandle(STD_OUTPUT_HANDLE);
    }
};


#endif //GRACHROME_CONSOLEWINDOW_H
