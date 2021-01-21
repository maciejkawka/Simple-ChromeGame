//
// Created by Maciej on 2020-04-14.
//

#include "Przeszkoda.h"

Przeszkoda::Przeszkoda() {
    PixelNumber=0;
    Pixel = 0;
    isOnScreen=false;
}

Przeszkoda::Przeszkoda(int _X, int _Y, int _PixelNumber): PixelNumber(_PixelNumber), isOnScreen(false) {

    if(PixelNumber<=0)
        return;
    Pixel = new Point[PixelNumber];

    for(int i=0;i<PixelNumber;i++)
        Pixel[i] = Point(_X, _Y);
}

Przeszkoda::Przeszkoda(int _X, int _Y, int _PixelNumber, char _Symbol): PixelNumber(_PixelNumber), isOnScreen(false) {

    if(PixelNumber<=0)
        return;
    Pixel = new Point[PixelNumber];

    for(int i=0;i<PixelNumber;i++)
        Pixel[i] = Point(_X, _Y, _Symbol);
}

Przeszkoda::Przeszkoda(Przeszkoda & _OBJ){
    Pixel = new Point[_OBJ.GetPixelNumber()];
    for(int i=0;i<PixelNumber;i++) {
        Pixel[i].SetXY(_OBJ.GetPixel(i + 1)->GetX(), _OBJ.GetPixel(i + 1)->GetY());
        Pixel[i].SetSymbol(_OBJ.GetPixel(i+1)->GetSymbol());

    }
}

Przeszkoda::~Przeszkoda()
{
    delete [] Pixel;
}

void Przeszkoda::MoveUp() {
    for(int i=0;i<PixelNumber;i++)
        Pixel[i].MoveUp();
}

void Przeszkoda::MoveDown() {
    for(int i=0;i<PixelNumber;i++)
        Pixel[i].MoveDown();
}

void Przeszkoda::MoveLeft() {
    for(int i=0;i<PixelNumber;i++)
        Pixel[i].MoveLeft();
}

void Przeszkoda::MoveRight() {
    for(int i=0;i<PixelNumber;i++)
        Pixel[i].MoveRight();
}

void Przeszkoda::Draw() {
    for(int i=0;i<PixelNumber;i++)
        Pixel[i].Draw();
}

void Przeszkoda::Erase(){
    for(int i=0;i<PixelNumber;i++)
        Pixel[i].Erase();
}
void Przeszkoda::SetPixel(int _X, int _Y, int _Pixel){
    Pixel[_Pixel-1].SetXY(_X,_Y);


}
void Przeszkoda::SetPixel(int _X, int _Y, int _Pixel, char _Symbol){
    Pixel[_Pixel-1].SetXY(_X,_Y);
    Pixel[_Pixel-1].SetSymbol(_Symbol);

}
void Przeszkoda::ChangePosition(int _X,int _Y){

    for(int i=0; i<PixelNumber;i++)
        Pixel[i].SetXY(Pixel[i].GetX()+_X,Pixel[i].GetY()+ _Y);
}

bool Przeszkoda::Collsion(Przeszkoda* Obj){
    for(int j=1;j<=Obj->GetPixelNumber();j++){
        for(int i=1;i<=this->PixelNumber;i++)
            if(this->Pixel[i].Collsion(Obj->GetPixel(j)))
                return true;
    }
    return false;
}


void Przeszkoda::MoveAllAt(int _X, int _Y) {
    Point* Distance = new Point[PixelNumber];

    for(int i=1;i<PixelNumber;i++)
        Distance[i].SetXY(Pixel[i].GetX()-Pixel[0].GetX(),Pixel[i].GetY()-Pixel[0].GetY());

    Pixel[0].SetXY(_X,_Y);

    for(int i=1;i<PixelNumber;i++)
        Pixel[i].SetXY(Distance[i].GetX()+_X,Distance[i].GetY()+_Y);


}