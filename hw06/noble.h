#ifndef NOBLE_H
#define NOBLE_H

#include<string>
#include<vector>
#include<iostream>

namespace WarriorCraft{
	class Warrior;
	class Noble{
	public:
		Noble(const std::string& name);
		void hire(Warrior& warrior);
		size_t findIndexOfWarrior(Warrior& warrior);
		void fire(Warrior& warrior);
		int getTotalStrength();
		void battle(Noble& noble);
		std::string getName();
		friend std::ostream& operator<< (std::ostream& os, const Noble& noble);
	private:
		std::string name;
		std::vector <Warrior*> army;
	};
}
#endif