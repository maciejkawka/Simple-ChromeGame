#include <iostream>
#include "Point.h"
#include "Przeszkoda.h"
#include <conio.h>
#include <cstdlib>
#include<ctime>

#define CLOCKINTERRUPT 60
#define MAXTREES 10
void Floor();
char Jump(Przeszkoda* _Obj, int height);
void Gravitation(Przeszkoda* _Obj);
void FreqMove(Przeszkoda* _Obj);
void CounterUpdate();
void MoveTrees(Przeszkoda** Array);
void MoveTrees(Przeszkoda** Array, int _Y);
void StartNewTree(Przeszkoda** Array);
void Collision(Przeszkoda** Array, char & op, Przeszkoda* _Player);
Przeszkoda* Player();
Przeszkoda* Tree();
Przeszkoda* Cloud();


int counter=0;
int jumpCounter = 0;
int points=0;


int main() {
    int liczba;
    ConsoleWindow console;
    console.setcoursor(0,0);
    srand( time( NULL ) );
    Floor();
    Przeszkoda* _Player = Player();


    Przeszkoda* Occlusion[MAXTREES];
    for(int i=0;i<MAXTREES;i++)
        Occlusion[i] = Tree();

    Przeszkoda* _Cloud[MAXTREES];
    for(int i=0;i<MAXTREES;i++)
        _Cloud[i] = Cloud();

    _Cloud[0]->SetActive(true);




    char op='1';
    do{

        liczba =( std::rand() % 100 );

        if(_kbhit())
            op = _getch();

        if(op=='W'||op=='w')
            op=Jump(_Player, 6);


        if(counter%30==0&&liczba<30)
           StartNewTree(Occlusion);

        if(liczba<5&&counter%30==0)
           StartNewTree(_Cloud);

        MoveTrees(Occlusion);
        if(counter%5==0)
            MoveTrees(_Cloud,6);



        FreqMove(_Player);
        CounterUpdate();
        Collision(Occlusion,op,_Player);
        Sleep(20-(int)(points/8));

        ConsoleWindow p;
        p.gotoXY(0,1);
        std::cout<<points<<"  TEMPO "<<20-(int)(points/8);
    }while(op !='e');


    getchar();


}

void Floor(){

    Point Punkt[MAXLENGTH];
    for(int i=0; i<MAXLENGTH;i++) {
        Punkt[i] = Point(i, 30);
        Punkt[i].Draw();
    }
}

Przeszkoda* Cloud(){
    Przeszkoda* _Cloud = new Przeszkoda(0,0,10);
    _Cloud->SetPixel(6,3,1,')');
    _Cloud->SetPixel(5,3,2,'_');
    _Cloud->SetPixel(4,3,3,'_');
    _Cloud->SetPixel(3,3,4,'_');
    _Cloud->SetPixel(2,3,5,'_');
    _Cloud->SetPixel(1,3,6,'(');
    _Cloud->SetPixel(2,2,7,'(');
    _Cloud->SetPixel(5,2,8,')');
    _Cloud->SetPixel(3,1,9,'_');
    _Cloud->SetPixel(4,1,10,'_');
    _Cloud->MoveAllAt(4,6);

    return _Cloud;
}

Przeszkoda* Player()
{
    Przeszkoda* _Player = new Przeszkoda(0,0,14,'#');
    _Player->SetPixel(1,1,1,',');
    _Player->SetPixel(2,1,2,'_');
    _Player->SetPixel(3,1,3,'_');
    _Player->SetPixel(4,1,4,'_');
    _Player->SetPixel(4,1,5,',');
    _Player->SetPixel(1,2,6,'(');
    _Player->SetPixel(2,2,7,'0');
    _Player->SetPixel(3,2,8,',');
    _Player->SetPixel(4,2,9,'0');
    _Player->SetPixel(5,2,10,')');
    _Player->SetPixel(1,3,11,'/');
    _Player->SetPixel(2,3,12,')');
    _Player->SetPixel(3,3,13,'_');
    _Player->SetPixel(4,3,14,')');
    _Player->MoveAllAt(4,MAXHEIGHT-2);

   _Player->Draw();
   _Player->SetActive(true);

    return _Player;

}

Przeszkoda* Tree(){
    Przeszkoda* _Tree = new Przeszkoda(0,0,9,'*');
    _Tree->SetPixel(1,2,9);
    _Tree->SetPixel(2,2,8);
    _Tree->SetPixel(3,2,7);
    _Tree->SetPixel(4,2,6);
    _Tree->SetPixel(5,2,5);
    _Tree->SetPixel(2,1,4);
    _Tree->SetPixel(3,1,3);
    _Tree->SetPixel(4,1,2);
    _Tree->SetPixel(3,0,1);
    _Tree->MoveAllAt(MAXLENGTH-5,MAXHEIGHT-2);
    return _Tree;
}

char Jump(Przeszkoda* _Obj, int height)
{

     if (jumpCounter<=height-1) {
        _Obj->Erase();
        if(jumpCounter==0)
            _Obj->MoveUp();
        _Obj->MoveUp();
        _Obj->Draw();
        jumpCounter++;
        return 'W';
        }
     else if(jumpCounter>height-1&&jumpCounter<=height) {
         jumpCounter++;
         return 'w';
     }
     else if(jumpCounter>height&&_Obj->GetPixel(1)->GetY() < MAXHEIGHT-2){
            if(counter%2!=0)
                return 'w';
          Gravitation(_Obj);
          jumpCounter++;
          return 'W';
        }
     else if(_Obj->GetPixel(1)->GetY() == MAXHEIGHT-2){
         jumpCounter=0;
         return '1';
     }

     return '1';

}

void Gravitation(Przeszkoda* _Obj)
{


        _Obj->Erase();
        _Obj->MoveDown();
        _Obj->Draw();


}


void FreqMove(Przeszkoda* _Obj){

   if(counter==10)
   {
       _Obj->Erase();
     for(int i=1;i<=10;i++)
         _Obj->GetPixel(i)->MoveRight();
     _Obj->Draw();

   }
   else if(counter==15)
   {
       _Obj->Erase();
       for(int i=1;i<=10;i++)
           _Obj->GetPixel(i)->MoveLeft();
       _Obj->Draw();
   }




}

void CounterUpdate(){
    if(counter==CLOCKINTERRUPT)
        counter=0;
    else
        counter++;
}

void MoveTrees(Przeszkoda** Array){
    for(int i=0;i<MAXTREES;i++)
    {
        if(Array[i]->GetActive()==true)
        {
            if(Array[i]->GetPixel(9)->GetX()>1) {
                Array[i]->Erase();
                Array[i]->MoveLeft();
                Array[i]->Draw();
            } else{
                Array[i]->Erase();
                Array[i]->MoveAllAt(MAXLENGTH-5,MAXHEIGHT-2);
                Array[i]->SetActive(false);
                points++;

            }
        }

    }

}

void MoveTrees(Przeszkoda** Array, int _Y){
    for(int i=0;i<MAXTREES;i++)
    {
        if(Array[i]->GetActive()==true)
        {
            if(Array[i]->GetPixel(9)->GetX()>1) {
                Array[i]->Erase();
                Array[i]->MoveLeft();
                Array[i]->Draw();
            } else{
                Array[i]->Erase();
                Array[i]->MoveAllAt(MAXLENGTH-5,_Y);
                Array[i]->SetActive(false);
                points++;

            }
        }

    }

}

void StartNewTree(Przeszkoda** Array){


    for(int i=0;i<MAXTREES;i++)
    {
        if(Array[i]->GetActive()==false){
            Array[i]->SetActive(true);
            return;
        }
    }

}

void Collision(Przeszkoda** Array,char & op,Przeszkoda* _Player){
    for(int i=0;i<MAXTREES;i++) {
        if (_Player->Collsion(Array[i])) {
            system("cls");
            std::cout << "PRZEGRALES";
            op= 'e';
        }

    }

}