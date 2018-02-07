#include "Pokemon.h"
#include "waterType.h"
#include "fireType.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main(){
   waterType w1("Squirtle","Blue",100,false);
   fireType f1("Charmandar","Red",110,true);
   Pokemon * base_ptr = &w1;
   fireType * derived_ptr = &f1;
   base_ptr->print();
   cout << "That was a close one!" << endl;
   cout << endl;

   derived_ptr->print();
   cout << "That was an even closer one!" << endl;
   cout << endl;

   waterType w2("Garados","Teal",170,true);
   fireType f2("Magmar","Orange",110,true);
   base_ptr = &w2;
   derived_ptr = &f2;
   base_ptr->print();
   cout << "That was even closer!" << endl;
   cout << endl;

   derived_ptr->print();
   cout << "Woah!" << endl;
   cout << endl;

   waterType w3("Magicarp","Blue",1,false);
   fireType f3("Charzard","Red",110,true);
   base_ptr = &w3;
   derived_ptr = &f3;
   base_ptr->print();
   cout << "That was close!" << endl;
   cout << endl;

   derived_ptr->print();
   cout << "That was insane!" << endl;
   cout << endl;
}
