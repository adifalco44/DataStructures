// Implementation for column class
// Author: Anthony Di Falco
#include <iostream>
#include <iterator>
#include <cmath>
#include "C4Col.h"
using namespace std;

// Constructor

C4Col::C4Col(){
   numDiscs = 0;
   maxDiscs = 6;
   Disc = new char [6];
   for (int it = 0; it < 6; it++){
      Disc[it] = ' ';
   }
}
// Destructor

C4Col::~C4Col(){
   delete []  Disc;
}

// Checks to see if Column is full

int C4Col::isFull(){
  int result = 0;
  if (numDiscs == maxDiscs){  //checks to see if col is full
     result = 1;
  }
  if (numDiscs != maxDiscs){  //not full
     result = 0;
  }
  return result;
}

// Returns disc's team

char C4Col::getDisc(int a){
     return Disc[a];
}

// Returns max discs

int C4Col::getMaxDiscs(){
   return maxDiscs;
}

// Adds disc to char array

void C4Col::addDisc(char newDisc){
   if (numDiscs != maxDiscs){ 
      Disc[numDiscs++] = newDisc;
   }else{
      cout << "Sorry that column is already full!" << endl;
   }
}
