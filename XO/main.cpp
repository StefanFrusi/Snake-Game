#include <iostream>

using namespace std;
int nrPlaceables(char*arr[9])
{int nr=0;
 for(int i=0;i<9;i++)
 {
     if(arr[i]==" ")
        nr++;

 }
    return nr;
}

int isWinner(char*arr[9],char*letter)
{if(arr[0]==letter&&arr[1]==letter&&arr[2]==letter)
return 1;
if(arr[3]==letter&&arr[4]==letter&&arr[5]==letter)
return 1;
if(arr[6]==letter&&arr[7]==letter&&arr[8]==letter)
return 1;
if(arr[0]==letter&&arr[3]==letter&&arr[6]==letter)
return 1;
if(arr[1]==letter&&arr[4]==letter&&arr[7]==letter)
return 1;
if(arr[2]==letter&&arr[5]==letter&&arr[8]==letter)
return 1;
if(arr[0]==letter&&arr[4]==letter&&arr[8]==letter)
return 1;
if(arr[2]==letter&&arr[4]==letter&&arr[6]==letter)
return 1;
return 0;
}
int  isDraw(char*arr[9])
{if(isWinner(arr,"X")==0&&isWinner(arr,"O")==0&&nrPlaceables(arr)==0)
  return 1;
  else
  return 0;
}


int bestScore(char*arr[9],bool isMaximising)
{ if(isWinner(arr,"X"))
    return 1*(nrPlaceables(arr)+1);
  if(isWinner(arr,"O"))
    return-1*(nrPlaceables(arr)+1);
  if(isDraw(arr))
    return 0;
if(isMaximising)
{int scorMax=-9999;
 for(int i=0;i<9;i++)
 {if(arr[i]==" ")
  {arr[i]="X";
   int scor=bestScore(arr,false);
   if(scor>scorMax)
    scorMax=scor;
   arr[i]=" ";}

 }
    return scorMax;
}
if(!isMaximising)
{int scorMax=9999;
 for(int i=0;i<9;i++)
 {if(arr[i]==" ")
  {arr[i]="O";
   int scor=bestScore(arr,true);
   if(scor<scorMax)
    scorMax=scor;
   arr[i]=" ";}

 }
    return scorMax;
}


}
int bestMove(char*arr[9])
{int scorMax=-9999;
 int pozitie;
    for(int i=0;i<9;i++)
{if(arr[i]==" ")
{arr[i]="X";
  int scor;
  scor=bestScore(arr,false);
  if(scorMax<scor)
  {scorMax=scor;
   pozitie=i;

   }
   arr[i]=" ";


}


}
 return pozitie;

}
void printBoard(char*arr[9])
{ for(int i=0;i<9;i++)
  {if(i==0)
  cout<<"-------"<<endl;
      if(i%3==0)
   cout<<"|";
   cout<<arr[i]<<"|";
   if((i+1)%3==0)
    cout<<endl<<"-------"<<endl;
    }


}
void startGame(char*arr[9])
{for(int i=0;i<9;i++)
 {if(i%2==0)
 {int move=bestMove(arr);
   arr[move]="X";
   printBoard(arr);

   if(isWinner(arr,"X"))
    {cout<<"X a castigat";
   break;
    }
    cout<<endl<<endl;
    if(isDraw(arr))
      {

        cout<<"remiza";
        break;}
 }
 else{
    cout<<"dati un numar la care sa plasati O: ";
    int nr;
    cin>>nr;
    arr[nr-1]="O";
    if(isWinner(arr,"O"))
    {cout<<"O a castigat";
    break;

    }
 if(isDraw(arr))
      {

        cout<<"remiza";
        break;}
 }

 }

}

int main()
{ char*arr[9];
for(int i=0;i<9;i++)
    arr[i]=" ";
startGame(arr);


    return 0;
}
