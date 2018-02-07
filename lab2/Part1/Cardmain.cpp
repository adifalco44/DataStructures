// Author: Anthony Di Falco
#include <iostream>
#include <iomanip>
#include "CardDeck.h"
using namespace std;

int main(){
   CardDeck test(10);
   cout << test;
   test.shuffle();
   cout << test;
}
