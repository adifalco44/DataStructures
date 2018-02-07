// Author: Anthony Di Falco
#include <iostream>
#include <iomanip>
#include "CardDeck.h"
using namespace std;

int main(){
   // Initializations
   CardDeck test(52);
   bool flag = false;
   int tmp1 [11];
   int tmp2 [11];
   int card;
   int count = 0;
   int wins = 0;
   int hit,type;
   bool round,shuffleIt;
   int choice;
   cout << "Welcome to Blackjack!" << endl;
   // Runs until user quits
   while (!flag){
      card = 0;
      count++;
      round = false;
      while (!round){
         // Shuffles && creates new deck if only 15 cards left
         shuffleIt = test.checkDeck();
         if (shuffleIt){
            for (int i = 0; i < 11; i++){
	       tmp1[i] = test.getHand1(i);
	       tmp2[i] = test.getHand2(i);
            }
            CardDeck test(52);
            for (int i = 0; i < 11; i++){
	       test.setHand1(i,tmp1[i]);
	       test.setHand2(i,tmp2[i]);
            }
            cout << " Shuffling . . . " << endl;            
         }
         cout << "Hit (press 0) or stay (press 1)?" << endl;
         cin >> hit;
	 test.addCard(card,hit);     // adds card based on input
         card++;                     // iterates to next card in hand
         type =  test.checkWin(hit); // tells who won if someone has  
         test.print1();              // prints hand
         // Enters iff game ends
         if (type != 0){
            if (type == 1){
		cout << "Congrats!" << endl;
                wins++;
            }
            round = true;
         }  
      }
      // Runs when game is over
      test.resetHand(); 
      cout << "To play again, press 1, to quit, press 0" << endl;
      cin >> choice;
      // Quits
      if (choice == 0){
          flag = true;
      } 
   } 
   cout << " Thanks for playing! You played " << count 
	<< " games and won " << wins << " times. Peace!" << endl;
}
