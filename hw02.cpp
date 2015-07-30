/*
hw02.cpp
programmer : Kristin Moser
This program reads commands from a file that will be preformed by a warrior and her weapon. These commands include the creation, battling, and displaying of the warriors.
The warrior is its own class and the weapon that the warrior is created with is also in its own class. The "warrior's strength" is stored withing the weapon. 
*/

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Weapon{

public:
	Weapon(string& weaponType, int& weaponStrength) :type(weaponType), strength(weaponStrength){}

	string getType()const{
		return type;
	}

	void setType(string newType){
		type = newType;
	}
	void setStrength(int newStrength){
		strength = newStrength;
	}
	int getStrength()const{
		return strength;
	}

	void display()const{
		cout << "weapon:" << type << "," << strength << endl;
	}

private:
	string type;
	int strength;

};

class Warrior{
public:
	Warrior(string& warriorName, Weapon& warriorWeapon): name(warriorName), weapon(warriorWeapon) {}
	
	string getName()const{
		return name;
	}
	void setName(string newName) {
		name = newName;
	}
	void display()const{
		cout << "warrior:" << name << " ";
		weapon.display();
	}
	int getWeaponStrength()const{
		return weapon.getStrength();
	}
	void setWeaponStrength(int newStrength){
		weapon.setStrength(newStrength);
	}

private:
	string name;
	Weapon weapon;

};




void createWarriorAndAddToVector(ifstream& ifs, vector<Warrior>& Warriors){
	//initializes a new warrior and its weapon and adds it to the vector
	string name;
	string typeOfWeapon;
	int strength;
	ifs >> name >> typeOfWeapon >> strength;
	Weapon aWeapon(typeOfWeapon, strength);
	Warrior aWarrior(name, aWeapon);
	Warriors.push_back(aWarrior);
}


void battle(Warrior& warrior1, Warrior& warrior2){
	//takes two warriors and compares their weapon strength. if one is higher than the others, the weaker one dies. if they have the same, they both die
	cout << warrior1.getName() << " battles " << warrior2.getName() << endl;
	if (warrior1.getWeaponStrength() > warrior2.getWeaponStrength()){
		warrior1.setWeaponStrength(warrior1.getWeaponStrength() - warrior2.getWeaponStrength());
		warrior2.setWeaponStrength(0);
		cout << warrior2.getName() << " is dead " << endl;
	}
	else if (warrior1.getWeaponStrength() < warrior2.getWeaponStrength()){
		warrior2.setWeaponStrength(warrior2.getWeaponStrength() - warrior1.getWeaponStrength());
		warrior1.setWeaponStrength(0);
		cout << warrior1.getName() << " is dead " << endl;

	}
	else{
		warrior1.setWeaponStrength(0);
		warrior2.setWeaponStrength(0);
		cout << "Mutual Annihilation : " << warrior1.getName() << " and " << warrior2.getName() << " die at each other's hands " << endl;
	}


}

void findTheFightersAndBattle(ifstream& ifs, vector<Warrior>& Warriors){
	//finds the fighters that need to battle and calls the battle function
	string fighter1;
	string fighter2;
	int indexOfFighter1;
	int indexOfFighter2;
	ifs >> fighter1 >> fighter2;
	for (size_t i = 0; i < Warriors.size(); ++i){
		if (Warriors[i].getName() == fighter1){
			indexOfFighter1 = i;
		}
		else if (Warriors[i].getName() == fighter2){
			indexOfFighter2 = i;
		}
	}

	battle(Warriors[indexOfFighter1], Warriors[indexOfFighter2]);
}

void showStatus(const vector<Warrior>& Warriors){
	//displays all the warriors in the vector using the warrior class display method
	int numOfWarriors = Warriors.size();
	cout << "There are: " << numOfWarriors << " warriors" << endl;
	for (size_t i = 0; i < Warriors.size(); ++i){
		Warriors[i].display();
	}
}


int main(){

	ifstream ifs("warriors.txt");
	if (!ifs) {
		cerr << "Failed to open file\n";
		exit(1);
	}
	string action;
	vector<Warrior> Warriors;
	while (ifs >> action){
		if (action == "Warrior"){
			createWarriorAndAddToVector(ifs, Warriors);
			}

		else if (action == "Status"){
			showStatus(Warriors);
			}
		else if (action == "Battle"){
			findTheFightersAndBattle(ifs, Warriors);
			}
		}
	ifs.close();
	system("pause");
}