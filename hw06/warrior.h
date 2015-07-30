#ifndef WARRIOR_H
#define WARRIOR_H

#include<string>
#include<vector>
#include<iostream>

namespace WarriorCraft{
	class Noble;
	class Warrior{
	public:
		Warrior(const std::string& name, int strength);
		std::string getName();
		int getStrength();
		Noble* getBoss();
		void setStrength(int newStrength);
		void runaway();
		std::string getBossName();
		void setBoss(Noble* boss);
		void display();

	private:
		std::string name;
		int strength;
		Noble* boss;

	};
}
#endif