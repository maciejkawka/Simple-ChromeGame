#include "Point.h"

#ifndef GRACHROME_PRZESZKODA_H
#define GRACHROME_PRZESZKODA_H


class Przeszkoda {

    Point* Pixel;
    int PixelNumber;
    bool isOnScreen;

public:
    Przeszkoda();
    Przeszkoda(int _X, int _Y, int _PixelNumber);
    Przeszkoda(int _X, int _Y, int _PixelNumber, char _Symbol);
    Przeszkoda(Przeszkoda & _OBJ);
    ~Przeszkoda();

    int GetPixelNumber(){return PixelNumber;}
    Point* GetPixel(int i){return (Pixel+i-1);}
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void Draw();
    void Erase();
    void SetPixel(int  _X, int _Y, int _Pixel);
    void SetPixel(int _X, int _Y, int _Pixel, char _Symbol);
    void ChangePosition(int _X,int _Y);
    bool Collsion(Przeszkoda* Obj);
    void MoveAllAt(int _X, int _Y);
    void SetActive(bool Active){isOnScreen=Active;}
    bool GetActive(){return isOnScreen;}


};


#endif //GRACHROME_PRZESZKODA_H
