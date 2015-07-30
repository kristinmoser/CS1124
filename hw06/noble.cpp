#include "warrior.h"
#include "noble.h"
#include <string>
#include <vector>

using namespace std;

namespace WarriorCraft{
	Noble::Noble(const string& name) : name(name), army(0, 0){}

	void Noble::hire(Warrior& warrior){
		army.push_back(&warrior);
		warrior.setBoss(this);
	}

	std::string Noble::getName(){
		return name;
	}

	size_t Noble::findIndexOfWarrior(Warrior& warrior){
		//finds the index of the warrior passed into the parameter
		if (army.size() == 0){
			for (size_t i = 0; i < army.size(); ++i){
				if (army[i] == &warrior){
					return i;
				}
			}
		}
		return 0;
	}
	void Noble::fire(Warrior& warrior){
		//finds the index of the warrior being fired then shifts the vector (overwriting the fired warrior and deletes the last warrior(which is a copy)
		size_t i = findIndexOfWarrior(warrior);
		for (size_t j = i; j < army.size() - 1; ++j){
			army[j] = army[j + 1];
		}
		army.pop_back();
	}
	int Noble::getTotalStrength(){
		//gets the total strength of the army
		int totalStrength = 0;
		for (size_t i = 0; i < army.size(); ++i){
			totalStrength += army[i]->getStrength();
		}
		return totalStrength;
	}


	void Noble::battle(Noble& noble){
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
	std::ostream& operator<<(std::ostream& os, const Noble& noble){
		os << noble.name << " has an army of size " << noble.army.size() << std::endl;
		for (size_t i = 0; i < noble.army.size(); ++i){
			noble.army[i]->Warrior::display();
		}
		return os;
	}
}