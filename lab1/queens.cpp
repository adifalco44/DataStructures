#include <iomanip>
#include <array>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void print(int board[8][8]){
   for (int i = 0; i < 8; i++){
      for (int j = 0; j < 8; j++){
	  cout << board[i][j] << " ";
      }
      cout << endl;
   }
}

bool checkSpot(int board[8][8], int row, int col){
  int i,j;

  for (i = 0; i < col; i++){
     if (board[row][i]){
	return false;
     } 
  }

  for (i = row, j = col; i >= 0 && j >= 0; i--, j--){
     if (board[i][j]){
	return false;
     }
  }

  return true;

}

bool findSol(int board[8][8], int col){
   if (col >= 8){
      return true;
   }
   for (int i = 0; i < 8; i++){
      if (checkSpot(board,i,col)){
	  board[i][col] = 1;
	  if (findSol(board,col + 1) == true){
              return true;
          }
          board[i][col] = 0;
      }
   }
   return false;
}

bool solve(){
   int board[8][8] = {0};
   if (findSol(board,0) == false){
      cout << "Solution does not exist" << endl;
      return false;
   }
   print(board);
   return true;

}

int main(){
   solve();
   return 0;

}

