/*
hw03.cpp
username: km3322
name: Kristin Moser
oop spring 2015
*/

#include <vector>
#include <string>
#include <iostream>
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
		for (size_t j = i; j < army.size()-1; ++j){
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
				float ratio = 1 - (float) getTotalStrength() / noble.getTotalStrength();
				cout << ratio << endl;
				for (size_t i = 0; i < noble.army.size(); ++i){
					noble.army[i]->setStrength((int) floor(noble.army[i]->getStrength() * ratio));
				}
				for (size_t i = 0; i < army.size(); ++i){
					army[i]->setStrength(0);
				}
			}
			if (noble.getTotalStrength() < getTotalStrength()){
				cout << noble.name << " is defeated." << endl;
				float ratio = 1 - (float) noble.getTotalStrength() / getTotalStrength();
				for (size_t i = 0; i < army.size(); ++i){
					army[i]->setStrength((int) floor(army[i]->getStrength() * ratio));
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


int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
	system("pause");
}