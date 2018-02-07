#ifndef POKEMON_H
#define POKEMON_H
#include <string>
using namespace std;

class Pokemon {
   public:
	Pokemon(string = "noname",string = "nocolor",int = 0,bool = false);
        virtual void print() = 0;
	string getName();
	string getColor();
	int getAttack();	
	bool getSex();
	
   private:
	string name;
	string color;
	int attack;
        bool sex;
};

#endif
