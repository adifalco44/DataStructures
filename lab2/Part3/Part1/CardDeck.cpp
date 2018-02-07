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
   for (int i = 0; i < a; i++){  // Initializes deck

      Deck[i] = i;
   } 
   size = a;

   for (int j = 0; j < 11; j++){ // Initializes player hand
      hand1[j] = 0;
   }
   for (int i = 0; i < 11; i++){ // Initianlizes computer hand
      hand2[i] = 0;
   }


}

// Deconstuctor

CardDeck::~CardDeck(){
   delete [] Deck;
}

// Returns Size

int CardDeck::getSize(){
   return size;
}

// Resets hand every time the player wants to play again

void CardDeck::resetHand(){
   for (int i = 0; i < 11; i++){
      hand1[i] = 0;
   }
   for (int i = 0; i < 11; i++){
      hand2[i] = 0;
   }
}

// Shuffles Deck  -- Yates algorithm

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

// Adds Card to Players hand & Computeres based on input (determined in main file)

void CardDeck::addCard(int a, int b){

   // Initializations
   int c;
   time_t t;
   srand((unsigned) time(&t));

   // Picks random card from deck and adds to user hand
   if (b == 0){
	   c = rand() % size; 
	   hand1[a] = Deck[c];

           // Sets 'empty' cards (aka -1's) to back of deck
	   for (int i = c; i < size - 1; i++){
	      Deck[i] = Deck[i+1];
	   }
	   Deck[size] = -1;
	   size--;
   }


   // Tally's computers hand
   int total = 0;
   for (int i = 0; i < 11; i++){
      total+= hand2[i]%12;
   }

   // Picks for computer if total is under 17
   if (total < 17){
      c = rand() % size; 
      hand2[a] = Deck[c];
      for (int i = c; i < size - 1; i++){
         Deck[i] = Deck[i+1];
      }
      Deck[size] = -1; 
      size--;
   }

}


// Simple Print Function
void CardDeck::print1(){

   // Prints users cards
   cout << "Your hand: ";
   for (int i = 0; i < 11; i++){
      if (hand1[i]%12 != 0 && hand1[i] != 1 && hand1[i] != 11) {             // Used to omit 0's in hand
         cout << ", " << hand1[i]%12;
      }
      if (hand1[i] == 11){
	 cout << ", " << "10";
      }
      if (hand1[i] == 1){
	 cout << ", " << "11";
      }
   }
   cout << endl;

   // Prints computers cards
   cout << "Their hand: " << hand2[0]%12;
   for (int i = 1; i < 11; i++){
      if (hand2[i]%12 != 0 && hand2[i] != 1 && hand2[i] != 11){
         cout << ", " << hand2[i]%12;
      }
      if (hand2[i] == 11){
	 cout << ", " << "10";
      }
      if (hand2[i] == 1){
	 cout << ", " << "11";
      }
   }
   cout << endl;

}

// Checks to see if deck needs to be shuffled

bool CardDeck::checkDeck(){
   int count = 0;
   for (int i = 0; i < 52; i++){
      if (Deck[i] == -1){
         count++;
      }      
   }
   if (count > 35){
      return true;
   }else{
      return false;
   }
}

// Utility functions for when new object is 
// created -- done when deck is shuffled

int CardDeck::getHand1(int a){
   return hand1[a];
}

int CardDeck::getHand2(int a){
   return hand2[a];
}

void CardDeck::setHand1(int a, int b){
   hand1[a] = b;
}

void CardDeck::setHand2(int a, int b){
   hand2[a] = b;
}



// Checks to see who wins

int CardDeck::checkWin(int move){
   int total = 0;
   int total2 = 0;
   for (int i = 0; i < 11; i++){
      if (hand1[i]%12 != 0 && hand1[i] != 1 && hand1[i] != 11){
         total=total+hand1[i]%12;
      }
      if (hand1[i] == 0 | hand1[i] == 11){
	 total=total+10;
      }
      if (hand1[i] == 1){
	 total=total+11;
      }
   }
   for (int i = 0; i < 11; i++){
       if (hand2[i]%12 != 0 && hand2[i] != 1 && hand2[i] != 11){
         total2=total2+hand2[i]%12;
      }
      if (hand2[i] == 0 | hand2[i] == 11){
	 total2=total2+10;
      }
      if (hand2[i] == 1){
	 total2=total2+11;
      }
      
   }
 
   if (total > 21){
      return 2;
   }else if (total < 22 && total > total2 && total2 > 16 ){
      return 1;
   }else if (total < 21 && total2 > 21){
      return 1;
   }else{
      return 0;
   } 
}

// Overloaded operator (unused)

ostream& operator<< (ostream &s, CardDeck&c){
   s << c.Deck[0];
   for (int i = 1; i < c.size; i++){
      s << " , " << c.Deck[i];
   }
   s << endl;
   return s;
}

