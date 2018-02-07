#include <cmath>
#include <iomanip>
using namespace std;
#ifndef CARDDECK_H
#define CARDDECK_H
class CardDeck{
   friend ostream& operator<<(ostream &, CardDeck &);
   public:
	CardDeck(int);
	~CardDeck();
	int getSize();
	void shuffle();
        void resetHand();
        void addCard(int,int);
        void print1();
	int checkWin(int);
        bool checkDeck();
        int getHand1(int);
        int getHand2(int);
        void setHand1(int,int);
        void setHand2(int,int);
   private:
	int * Deck;
        int size;
        int hand1[11];
        int hand2[11];
};

#endif
