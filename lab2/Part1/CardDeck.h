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
   private:
	int * Deck;
        int size;
};

#endif
