// Author: Anthony Di Falco
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "fireType.h"

fireType::fireType (string name, string color, int attack, bool sex) : Pokemon (name,color,attack,sex){}

void fireType::print(){
   string gender;
   if (getSex()){
      gender = "Male";
   }else{
      gender = "Female";
   }
   cout << "Watch out, it's a fire type!" << endl;
   cout << "Pokemon name: " << getName() << endl;
   cout << "Pokemon color: " << getColor() << endl;
   cout << "Pokemon attack damage: " << getAttack() << endl;
   cout << "Pokemon sex: " << gender << endl;
}
