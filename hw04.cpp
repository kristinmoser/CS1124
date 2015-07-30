#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Warrior{
public:
	Warrior(const string& name, int strength) : name(name), strength(strength) {}
	string getName(){
		return name;
	}
	int getStrength(){
		return strength;
	}

	void setStrength(int newStrength){
		strength = newStrength;
	}

	void display(){
		cout << name << "," << strength << endl;
	}


private:
	string name;
	int strength;

};

class Noble{

public:
	Noble(const string& name) : name(name), army(NULL){}

	string getName()const{
		return name;
	}

	void hire(Warrior& warrior){
		army.push_back(&warrior);
	}

	size_t findIndexOfWarrior(Warrior& warrior){
		//finds the index of the warrior passed into the parameter
		for (size_t i = 0; i < army.size(); ++i){
			if (army[i] == &warrior){
				return i;
			}
		}
	}
	void fire(Warrior& warrior){
		//finds the index of the warrior being fired then shifts the vector (overwriting the fired warrior and deletes the last warrior(which is a copy)
		size_t i = findIndexOfWarrior(warrior);
		for (size_t j = i; j < army.size() - 1; ++j){
			army[j] = army[j + 1];
		}
		army.pop_back();
	}
	int getTotalStrength(){
		//gets the total strength of the army
		int totalStrength = 0;
		for (size_t i = 0; i < army.size(); ++i){
			totalStrength += army[i]->getStrength();
		}
		return totalStrength;
	}


	void battle(Noble& noble){
		/*if one or either are already dead, there is no battle. if one is larger,
		the smaller one's strength will be 0, and the larger one will lose a ratio
		of its strength based on the ratio of the smaller strength to larger strength
		*/
		cout << name << " battles " << noble.name << endl;
		if (noble.getTotalStrength() == 0 || getTotalStrength() == 0){
			cout << "One of these nobles' army is already dead. No battle takes place." << endl;
		}
		else{

			if (noble.getTotalStrength() > getTotalStrength()){
				cout << name << " is defeated" << endl;
				float ratio = 1 - (float)getTotalStrength() / noble.getTotalStrength();
				cout << ratio << endl;
				for (size_t i = 0; i < noble.army.size(); ++i){
					noble.army[i]->setStrength((int)floor(noble.army[i]->getStrength() * ratio));
				}
				for (size_t i = 0; i < army.size(); ++i){
					army[i]->setStrength(0);
				}
			}
			if (noble.getTotalStrength() < getTotalStrength()){
				cout << noble.name << " is defeated." << endl;
				float ratio = 1 - (float)noble.getTotalStrength() / getTotalStrength();
				for (size_t i = 0; i < army.size(); ++i){
					army[i]->setStrength((int)floor(army[i]->getStrength() * ratio));
				}
				for (size_t i = 0; i < noble.army.size(); ++i){
					noble.army[i]->setStrength(0);
				}
			}
			if (noble.getTotalStrength() == getTotalStrength()){
				cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
				for (size_t i = 0; i < army.size(); ++i){
					army[i]->setStrength(0);
				}
				for (size_t i = 0; i < noble.army.size(); ++i){
					noble.army[i]->setStrength(0);
				}

			}
		}
	}

	void display(){
		cout << "This is " << name << "'s army:" << endl;
		for (size_t i = 0; i < army.size(); ++i){
			army[i]->display();
		}
	}

private:
	string name;
	vector <Warrior*> army;
};

void createNewWarrior(ifstream& ifs, vector<Warrior*> warriors){
	//initializes a new warrior and its weapon and adds it to the vector
	string name;
	int strength;
	ifs >> name  >> strength;
	Warrior* warptr = new Warrior(name, strength);
	warriors.push_back(warptr);
}

void createNewNoble(ifstream& ifs, vector<Noble*> nobles){
	string nobleName;
	ifs >> nobleName;
	Noble* nobleptr = new Noble(nobleName);
	nobles.push_back(nobleptr);
}

int main(){
	ifstream ifs("nobleWarriors.txt");
	if (!ifs) {
		cerr << "Failed to open file\n";
		exit(1);
	}
	string action;
	vector<Warrior*> warriors;
	vector<Noble*> nobles;
	while (ifs >> action){
		if (action == "Noble"){
			createNewNoble(ifs, nobles);
		}
		else if (action == "Warrior"){
			createNewWarrior(ifs, warriors);
		}
		else if (action == "Hire"){
			//findTheFightersAndBattle(ifs, Warriors);
		}
		else if (action == "Fire"){
			//showStatus(Warriors);
		}
		else if (action == "Hire"){
			//findTheFightersAndBattle(ifs, Warriors);
		}
		else if (action == "Battle"){
			//showStatus(Warriors);
		}
		else if (action == "Status"){
			//findTheFightersAndBattle(ifs, Warriors);
		}
		else if (action == "Clear"){
			//showStatus(Warriors);
		}
	}
	ifs.close();
	system("pause");
}
