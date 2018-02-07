// Class Declaration for C4Board
// Author: Anthony Di Falco

#include "C4Col.h"
#ifndef C4BOARD_H
#define C4BOARD_H
class C4Board{
   public:
     C4Board();
     ~C4Board();
     void play(int);
     void display();
     bool checkWin();
     int AImode();

   private:
     int numCols;
     C4Col * board;
};

#endif
