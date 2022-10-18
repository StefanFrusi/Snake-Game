#include <iostream>
#include<vector>
using namespace std;
void nextEmpty(int arr[9][9],int row,int col,int &nextRow,int &nextCol)//FUNCTIE TESTATA
{int ok=0;
    for(int i=row;i<9;i++)
{for(int j=0;j<9;j++)
    if(arr[i][j]==0)
     {nextRow=i;
     nextCol=j;
     ok=1;
     break;
     }
     if(ok==1)
        break;
     }
}
void printBoard(int arr[9][9])//FUNCTIE TESTATA
{ cout<<"-------------------"<<endl;
    for(int i=0;i<9;i++)
    {for(int j=0;j<9;j++)
      cout<<arr[i][j]<<" ";
      cout<<endl;
    }
  cout <<"-------------------";
}
void arrCpy(int arr[9][9],int arrCpy[9][9])//FUNCTIE TESTATA
{ for(int i=0;i<9;i++)
  {for(int j=0;j<9;j++)
   {arrCpy[i][j]=arr[i][j];}}
}

bool isPlaceable(int arr[9][9],int row,int col,int n)//FUNCTIE TESTATA
{ for(int i=0;i<9;i++)
   if(arr[row][i]==n||arr[i][col]==n)
    return false;
  for(int i=row/3*3;i<row/3*3+3;i++)
    for(int j=col/3*3;j<col/3*3+3;j++)
    if(arr[i][j]==n)
    return false;
  return true;}



vector<int>findPlaceables(int arr[9][9],int row,int col)//FUNCTIE TESTATA
{ vector<int>placeabels={};
    for(int i=1;i<=9;i++)
 if(isPlaceable(arr,row,col,i))
  placeabels.push_back(i);
  return placeabels;}



bool solveSudoku(int arr[9][9],int row,int col)
{if(row>8)
return true;
if(arr[row][col]!=0)
{
     int nextCol,nextRow;
     nextEmpty(arr,row,col,nextRow,nextCol);
    return  solveSudoku(arr,nextRow,nextCol);
}
vector<int>placeables=findPlaceables(arr,row,col);
if(placeables.size()==0)
    return false;
    bool status=false;
    for(int i=0;i<placeables.size();i++)
    {int n=placeables[i];
     int copie[9][9];
     arrCpy(arr,copie);
     copie[row][col]=n;
     int nextCol,nextRow;
     nextEmpty(copie,row,col,nextRow,nextCol);
     if(solveSudoku(copie,nextRow,nextCol))
     {   arrCpy(copie,arr);
         status=true;
         break;}

}

return status;


}


int main()
{
  int board[9][9]={{5,3,0,0,7,0,0,0,0},
                   {6,0,0,1,9,5,0,0,0},
                   {0,9,8,0,0,0,0,6,0},
                   {8,0,0,0,6,0,0,0,3},
                   {4,0,0,8,0,3,0,0,1},
                   {7,0,0,0,2,0,0,0,6},
                   {0,6,0,0,0,0,2,8,0},
                   {0,0,0,4,1,9,0,0,5},
                   {0,0,0,0,8,0,0,7,9}};
                   printBoard(board);
                   int nextRow;int nextCol;
                   nextEmpty(board,3,8,nextRow,nextCol);
                   cout<<endl;
                   cout<<nextRow<<" "<<nextCol<<endl;
                   solveSudoku(board,0,0);
                   printBoard(board);

 return 0;}
