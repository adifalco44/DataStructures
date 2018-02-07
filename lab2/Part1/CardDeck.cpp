// Author: Anthony Di Falco

#include <iostream>
#include <cmath>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include "CardDeck.h"
using namespace std;

// Constructor

CardDeck::CardDeck(int a){
   Deck = new int [a];
   for (int i = 0; i < a; i++){
      Deck[i] = i;
   } 
   size = a;
}

CardDeck::~CardDeck(){
   delete [] Deck;
}

int CardDeck::getSize(){
   return size;
}

void CardDeck::shuffle(){
   int i,j,k,n;
   time_t t;
   srand((unsigned) time(&t));
   for (int i = 0; i < size - 2; i++){
      j = Deck[i];
      k = rand() % size;
      n = Deck[k];
      Deck[i] = n;
      Deck[k] = j;
   }
}

ostream& operator<< (ostream &s, CardDeck&c){\
   s << c.Deck[0];
   for (int i = 1; i < c.size; i++){
      s << " , " << c.Deck[i];
   }
   s << endl;
   return s;
}
