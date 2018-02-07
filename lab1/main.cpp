#include <iomanip>
#include <iostream>
#include "C4Board.h"
using namespace std;

int main(){
   int choice;
   C4Board c4;
   cout << "	Welcome to connect Four!" << endl
        << "  To play with friends, press 1" << endl
        << "To play with a computer, press 2" << endl;
   cin >> choice;
   c4.play(choice);
   return 0;
}
