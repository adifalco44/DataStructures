// Author: Anthony Di Falco
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "waterType.h"

waterType::waterType (string name, string color, int attack, bool sex) : Pokemon (name,color,attack,sex){}

void waterType::print(){
   string gender;
   if (getSex()){
	   gender = "Male";
   }else{
	   gender = "Female";
   }	
   cout << "Be careful, it's a water type!" << endl;
   cout << "Pokemon name: " << getName() << endl;
   cout << "Pokemon color: " << getColor() << endl;
   cout << "Pokemon attack damage: " << getAttack() << endl;
   cout << "Pokemon sex: " << gender << endl;
}
