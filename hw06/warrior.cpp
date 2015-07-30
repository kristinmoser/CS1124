#include "warrior.h"
#include "noble.h"
#include <string>
#include <vector>

using namespace std;

namespace WarriorCraft{
	Warrior::Warrior(const string& name, int strength) : name(name), strength(strength), boss(NULL) {}
	std::string Warrior::getName(){
		return name;
	}
	int Warrior::getStrength(){
		return strength;
	}
	Noble* Warrior::getBoss(){
		return boss;
	}

	void Warrior::setStrength(int newStrength){
		strength = newStrength;
	}

	void Warrior::display(){
		cout << name << ": " << strength << endl;
	}
	void Warrior::setBoss(Noble* newBoss){
		boss = newBoss;
	}
	std::string Warrior::getBossName(){
		return boss->getName();
	}
	void Warrior::runaway(){
		cout << name << " flees in terror, abandoning his lord, " << this->getBossName() << endl;
		if (boss != nullptr){
			boss->fire(*this);
			boss = nullptr;
		}
	}
}