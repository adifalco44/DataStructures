#include <string>

#include <iomanip>
#ifndef FIRETYPE_H
#define FIRETYPE_H
#include "Pokemon.h"
using namespace std;

class fireType : public Pokemon {
   public:
	fireType(string = "noname",string = "nocolor", int = 0, bool = false);
        virtual void print();
};

#endif


