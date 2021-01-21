

#include "Point.h"



Point::Point(): X(0), Y(0), Symbol('*'){

}

Point::Point(int _X, int _Y): X(_X), Y(_Y), Symbol('*'){

}

Point::Point(int _X, int _Y, char _Symbol): X(_X), Y(_Y), Symbol(_Symbol) {

}

void Point::SetXY(int _X, int _Y) {
    this->X = _X;
    this->Y = _Y;
}

void Point::Draw() {
    gotoXY(X,Y);
    std::cout<<Symbol;
}

bool Point::Collsion(Point*  _Obj){

    if(_Obj->GetX()==this->X&&_Obj->GetY()==this->Y)
        return true;
    else
        return false;
}


void Point::Erase(){
    gotoXY(X,Y);
    std::cout<<" ";
}

