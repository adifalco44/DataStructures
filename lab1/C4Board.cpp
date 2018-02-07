// Implementation for C4Board class
// Author: Anthony Di Falco
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "C4Board.h"
#include "C4Col.h"
using namespace std;

// Constructor

C4Board::C4Board(){
   numCols = 7;
   board = new C4Col [7];
}

// Deconstructor

C4Board::~C4Board(){
   delete [] board;
}

// Display Function

void C4Board::display(){

   // Outputs array
   for (int i = board[0].getMaxDiscs() - 1; i >= 0; i--){
      for (int j = 0; j < numCols; j++){
         cout << board[j].getDisc(i) << " |";
      }
      cout << endl;
   }

   // Creates index for use
   for (int i = 0; i < numCols; i++){
      cout << i << "  ";
   }
   cout << endl; 

}

// 2 Player function

void C4Board::play(int a){

   // Initializations
   int mode = a;
   int player = 1;
   bool win = false;
   int choice,full;
   display();
   bool found = false;

   // Runs until theres a winner
   while (win != true){

      if (player == 1 || mode == 1){
         cout << "Enter the column you wish to place in:";
         cin >> choice;
         cout << endl;
      }else{
         choice = AImode();
      }


      full = board[choice].isFull();
      if (full != 1){                        // runs if column isn't full
         if (choice < 7 && choice >= 0){     // runs if valid column
            if (player == 1){         
               board[choice].addDisc('X');
               player--;
            }else{
               board[choice].addDisc('O');
               player++;                   
	    }
         }else{
	     cout << "Invalid column" << endl;
         }
      }else{
         cout << "That column is full!" << endl;
      }
      display();  
      win = checkWin();
   }
   cout << "Game over!" << endl;
}

// Win Function

bool C4Board::checkWin(){
    //Initializations
    bool flag = false;
    int count1,count2,count3,count4,count5,count6,count7,count8;
    for (int i = board[0].getMaxDiscs() - 1; i >= 0; i--){ // iterates thru rows
        for (int j = 0; j < numCols; j++){                 // iterates thru cols
	    count1 = 0;
 	    count2 = 0;
 	    count3 = 0;
	    count4 = 0;
            if (j < 4){ //checks right
                for (int k = 1; k < 4; k++){
                   if (board[j].getDisc(i) == board[j+k].getDisc(i) && board[j].getDisc(i) != ' ' ){
			count1++;
	 	   }
                }                 
            }
	    if (i > 2){ // chekcs below
               for (int k = 1; k < 4; k++){
	           if (board[j].getDisc(i) == board[j].getDisc(i-k) && board[j].getDisc(i) != ' '){
			count2++;
                   }	
               }                 
            }
	    if (i > 2 && j < 4){ // checks horiz
               for (int k = 1; k < 4; k++){
	           if (board[j].getDisc(i) == board[j+k].getDisc(i-k) && board[j].getDisc(i) != ' ' ){
			count3++;
	 	   }
               }                 
            }
	    if (i < 3 && j < 4){ // checks horiz
               for (int k = 1; k < 4; k++){
	           if (board[j].getDisc(i) == board[j+k].getDisc(i+k) && board[j].getDisc(i) != ' ' ){
			count4++;
	 	   }
               }                 
            }
	    // declares win
            if (count1 == 3|| count2 == 3|| count3 == 3 || count4 == 3){
		flag = true;
            }
        }
    }
    return flag;
}

int C4Board::AImode(){

      // Initializations
      int i,n;
      time_t t;
      srand((unsigned) time(&t));

      // Returns random choice
      n = rand() % 7;
      n;
      while (board[n].isFull()){
         n = rand() % 7;
         n;
      }
      return n;       
}

