// C4Col class declaration file
// Author: Anthony Di Falco
using namespace std;

#ifndef C4COL_H
#define C4COL_H

class C4Col{
  public:

   C4Col();
   ~C4Col();

   int isFull();
   char getDisc(int);

   int getMaxDiscs();
   void addDisc(char);

  private:

   int maxDiscs;
   int numDiscs;
   char * Disc; 

};

#endif
