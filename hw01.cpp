/*
hw01.cpp
programmer : Kristin Moser
*/

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct Warrior{
	string name;
	int strength;
};

void battle(Warrior& warrior1, Warrior& warrior2);

void createWarriorAndAddToVector(ifstream& ifs, vector<Warrior>& Warriors){
	Warrior localWarrior;
	string localName;
	int localStrength;
	ifs >> localName >> localStrength;
	localWarrior.name = localName;
	localWarrior.strength = localStrength;
	Warriors.push_back(localWarrior);
}
void findTheFightersAndBattle(ifstream& ifs, vector<Warrior>& Warriors){
	string fighter1;
	string fighter2;
	int indexOfFighter1;
	int indexOfFighter2;
	ifs >> fighter1 >> fighter2;


	for (size_t i = 0; i < Warriors.size(); ++i){
		if (Warriors[i].name == fighter1){
			indexOfFighter1 = i;
		}
		else if (Warriors[i].name == fighter2){
			indexOfFighter2 = i;
		}
	}

	battle(Warriors[indexOfFighter1], Warriors[indexOfFighter2]);
}

void battle(Warrior& warrior1, Warrior& warrior2){
	cout << warrior1.name << " battles " << warrior2.name << endl;
	if (warrior1.strength > warrior2.strength){
		warrior1.strength -= warrior2.strength;
		warrior2.strength = 0;
		cout << warrior2.name << " is dead " << endl;

	}
	else if (warrior1.strength < warrior2.strength){
		warrior2.strength -= warrior1.strength;
		warrior1.strength = 0;
		cout << warrior1.name << " is dead " << endl;

	}
	else{
		warrior1.strength = 0;
		warrior2.strength = 0;
		cout << "Mutual Annihilation : " << warrior1.name << " and " << warrior2.name << " die at each other's hands " << endl;
	}


}

void showStatus(const vector<Warrior>& Warriors){
	int numOfWarriors = Warriors.size();
	cout << "There are: " << numOfWarriors << " warriors" << endl;
	for (size_t i = 0; i < Warriors.size(); ++i){
		cout << "Warrior:" << Warriors[i].name << ", strength:" << Warriors[i].strength << endl;
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
	while(ifs >> action){
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
