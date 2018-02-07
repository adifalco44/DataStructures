#include <iostream>
#include <string>
#include "Pokemon.h"
using namespace std;

Pokemon::Pokemon(string colr,string nm, int att, bool mf){
	name  = nm;
	color = colr;
	attack = att;
	sex = mf;
}

void Pokemon::print(){
        string gender;
	if (sex){
	   gender = "Male";
	}else{
	   gender = "Female";
	}
	cout << "Pokemon name:" << name << endl;
	cout << "Pokemon color:" << color << endl;
	cout << "Pokemon attack damage:" << attack << endl;
	cout << "Pokemon sex:" << gender << endl;
}


string Pokemon::getName(){
	return (name);
}


string Pokemon::getColor(){
	return (color);
}


int Pokemon::getAttack(){
	return (attack);
}


bool Pokemon::getSex(){
	return (sex);
}
