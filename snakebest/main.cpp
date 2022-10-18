#include <iostream>
#include<conio.h>
#include<windows.h>

using namespace std;
int latime=30;
int inaltime=15;
bool gameOver=false;
int scor=0;
struct object
{ int x;
int y;

};
object snake;
object fruct;
object coada[100];
int ncoada=0;
object cacat,prev2;

enum directii
{
    STOP,LEFT,RIGHT,DOWN,UP
};
directii dir;
void Setup()
{
snake.x=5;
snake.y=5;
srand(0);
fruct.x=rand()%latime;
fruct.y=rand()%inaltime;
dir=STOP;
}




void Draw()
{system("cls");//curatare sistem
    for(int i=0;i<latime;i++)
 { cout<<"#";
 }
 cout<<endl;
 for(int i=1;i<inaltime-1;i++)
  {

    for(int j=0;j<latime;j++)
    if(j==0||j==latime-1)
    cout<<"#";
    else if(i==snake.y&&j==snake.x)
         cout<<"O";
     else if(i==fruct.y&&j==fruct.x)
        cout<<"*";
        else{
            bool ecoada=false;
            for(int k=0;k<ncoada;k++)
                if(coada[k].x==j&&coada[k].y==i)
              {

                ecoada=true;
            break;}
            if(ecoada==true)
                cout<<"o";
                else
                  cout<<" ";
        }


    cout<<endl;
  }
for(int i=0;i<latime;i++)
 { cout<<"#";
 }
 cout<<endl;
 cout<<scor;
}
void input()
{if(_kbhit())
 {
     switch(_getch())

      {  case'a':dir=LEFT;
         break;
         case'd':dir=RIGHT;
         break;
         case'w':dir=UP;
         break;
         case's':dir=DOWN;
         break; }
 }

}
void action()
{cacat.x=snake.x;
cacat.y=snake.y;
    switch(dir)
    { case LEFT:snake.x--;
       break;
       case RIGHT:snake.x++;
       break;
       case DOWN:snake.y++;
       break;
       case UP:snake.y--;
       break;
     }
    if(snake.x==fruct.x&&snake.y==fruct.y)
    {   ncoada++;
        scor++;
        fruct.x=rand()%latime;
fruct.y=rand()%inaltime;

    }
    if(snake.x==0||snake.x==latime||snake.y==0||snake.y==inaltime)
        gameOver=true;
  for(int i=0;i<ncoada;i++)
       { prev2.x=coada[i].x;
         prev2.y=coada[i].y;
         coada[i].x=cacat.x;
         coada[i].y=cacat.y;
         cacat.x=prev2.x;
         cacat.y=prev2.y;


       }

}

int main()
{   Setup();
while(!gameOver)
    {   input();
        action();
        Draw();
        Sleep(40);
    }
    if(gameOver==true)
    {cout<<endl;
    cout<<"SFARSIT DE JOC";}
    return 0;
}
