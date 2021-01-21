#include <iostream>
#include "ConsoleWindow.h"
#ifndef GRACHROME_POINT_H
#define GRACHROME_POINT_H

#define MAXLENGTH 120
#define MAXHEIGHT 29

class Point:ConsoleWindow {

    int X;
    int Y;
    char Symbol;

public:
    Point();
    Point(int, int);
    Point(int, int ,char);

    ~Point(){

    }

    void MoveUp(){Y--;}
    void MoveDown() {Y++;}
    void MoveLeft(){X--;}
    void MoveRight(){X++;}
    void Draw();
    void SetSymbol(char _symbol) {Symbol=_symbol;};
    void SetXY(int _X, int _Y);
    void Debug(){std::cout<<"("<<X<<" "<<Y<<")";};
    bool Collsion(Point*);
    void Erase();
    int GetX(){return X;}
    int GetY(){return Y;}
    char GetSymbol(){return Symbol;}




};


#endif //GRACHROME_POINT_H
