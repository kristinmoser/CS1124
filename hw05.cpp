/*
Kristin Moser
hw05.cpp
username: km3322
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Noble {
public:
	Noble(const string& name) : name(name){}
	virtual string getName()const{
		return name;
	}
	virtual int getStrength(){
		return 1;
	}
	virtual void changeStrength(float ratio){
	}
	virtual void changeLifeStatus(bool status){
		lifeStatus = status;
	}
	virtual bool getLifeStatus(){
		return lifeStatus;
	}

private:	
	string name;
	bool lifeStatus;
};

class Protector{
public:
	Protector(const std::string& name, int strength) : name(name), strength(strength), ishired(false){}

	string getName(){
		return name;
	}
	int getStrength(){
		return strength;
	}
	void beHired(bool status){
		ishired = status;
	}
	bool getStatus(){
		return ishired;
	}
	virtual bool battleCry(){
		return false;
	}
	virtual  void changeStrength(float& ratio){
		strength = (int)floor(strength * ratio);
	}
private:
	bool ishired;
	string name;
	int strength;
};

class Lord : public Noble{
public:
	Lord(const string& name) : Noble(name), protectors(NULL){}
	void hires(Protector& protector){
		protectors.push_back(&protector);
		protector.beHired(true);
	}
	void changeStrength(float& ratio){
		for (size_t i = 0; i < protectors.size(); ++i){
			protectors[i]->changeStrength(ratio);
		}
	}
	int getStrength(){
		//gets the total strength of the army
		int totalStrength = 0;
		for (size_t i = 0; i < protectors.size(); ++i){
			totalStrength += protectors[i]->getStrength();
		}
		return totalStrength;
	}
	void battle(Noble& noble){
		cout << getName() << " battles " << noble.getName() << endl;
		if (getStrength() == 0 && getLifeStatus() == false){
			cout << "He's dead, " << noble.getName() << endl;
		}
			if (noble.getStrength() > getStrength()){
				cout << getName() << " is defeated" << endl;
				float ratio = 1 - (float)getStrength() / noble.getStrength();
				noble.changeStrength((int)floor(noble.getStrength() * ratio));
			}
		if (noble.getStrength() < getStrength()){
			cout << noble.getName() << " is defeated." << endl;
			float ratio = 1 - (float)noble.getStrength() / getStrength();
			noble.changeStrength(ratio);
			changeStrength(ratio);
		}
		if (noble.getStrength() == getStrength()){
			cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
			noble.changeStrength(0.0);
			noble.changeStrength(0.0);
		}
		if (protectors.size() != 0){
			for (size_t i = 0; i < protectors.size(); ++i){
				if (protectors[i]->getStrength() > 0){
					protectors[i]->battleCry();
				}
				if (protectors[i]->getStatus()){
					cout << protectors[i]->getName() << " says: Take that in the name of my lord, " << getName() << endl;
				}
			}
		}
	}

	
private:
	vector<Protector*> protectors;

};

class PersonWithStrengthToFight : public Noble{
public:
	PersonWithStrengthToFight(const string& name, int strength) : Noble(name), strength(strength){}
	void battle(Noble& noble){
		cout << getName() << " battles " << noble.getName() << endl;
		if (noble.getStrength() == 0 || getStrength() == 0){
			cout << "One of these nobles' army is already dead. No battle takes place." << endl;
		}
		else{
			if (noble.getStrength() > getStrength()){
				cout << getName() << " is defeated" << endl;
				float ratio = 1 - (float)getStrength() / noble.getStrength();
				noble.changeStrength((int)floor(noble.getStrength() * ratio));
			}
		}
		if (noble.getStrength() < getStrength()){
			cout << noble.getName() << " is defeated." << endl;
			float ratio = 1 - (float)noble.getStrength() / getStrength();
			noble.changeStrength(ratio);
			changeStrength(ratio);
		}
		if (noble.getStrength() == getStrength()){
			cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
			noble.changeStrength(0.0);
			noble.changeStrength(0.0);
		}
	}
	int getStrength(){
		return strength;
	}
private:
	int strength;
};


class Warrior : public Protector{
public:
	Warrior(const std::string& name, int strength) : Protector(name, strength){}
private:

};

class Wizard : public Protector{
public:
	Wizard(const std::string& name, int strength) : Protector(name, strength){}
	bool battleCry(){
		cout << "POOF" << endl;
		return false;
	}
private:

};

class Archer : public Warrior{
public:
	Archer(const std::string& name, int strength) : Warrior(name, strength){}
	bool battleCry(){
		cout << "TWANG! " << endl;
		return true;
	}
private:
};

class Swordsman : public Warrior{
public:
	Swordsman(const std::string& name, int strength) : Warrior(name, strength){}
	bool battleCry(){
		cout << "CLANG! " << endl;
		return true;
	}
private:
};

int main() {
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);
	system("pause");
}
