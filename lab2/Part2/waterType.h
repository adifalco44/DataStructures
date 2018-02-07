#include <string>

#include <iomanip>
#ifndef WATERTYPE_H
#define WATERTYPE_H
#include "Pokemon.h"
using namespace std;

class waterType : public Pokemon {
   public:
	waterType(string = "noname",string = "nocolor", int = 0, bool = false);
        virtual void print();
};

#endif


