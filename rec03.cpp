/* rec03.cpp
Kristin Moser
km3322
*/
#include <string>
#include <vector>
#include <ostream>
#include <iostream>

using namespace std;

class Sandwich{
public:
	Sandwich(int newTomatoes = 2 , int newCheese = 1, double newMayo = 1.0, double newMustard = .05 ): tomatoes(newTomatoes), cheese(newCheese), mayo(newMayo) , mustard(newMustard), bread(2){
	}
	int getBread()const{
		return bread;
	}
	int getCheese() const{
		return cheese;
	}
	int getTomatoes() const{
		return tomatoes;
	}
	double getMayo() const{
		return mayo;
	}
	double getMustard() const{
		return mustard;
	}

	void setCheese(int newCheese){
		cheese = newCheese;
	}
	void setTomatoes(int newTomatoes){
		tomatoes = newTomatoes;
	}
	void setMayo(double newMayo){
		mayo = newMayo;
	}
	void setMustard(double newMustard){
		mustard = newMustard;
	}
	void display() const {
		cout << "Bread Slices: " << bread << endl;
		cout << "Cheese slices: " << cheese << endl;
		cout << "Tomato slices: " << tomatoes << endl;
		cout << "Ounces of Mayo: " << mayo << endl;
		cout << "Ounces of Mustard: " << mustard << endl;
	}

private:
	const int bread;
	int cheese;
	int tomatoes;
	double mayo;
	double mustard;

};

class SandwichTruck {
public:
	void addSandwich(Sandwich& newSandwich){
		Sandwiches.push_back(newSandwich);
	}
	void display() const {
		for (int i = 0; i < Sandwiches.size(); i++){
			Sandwiches[i].display();
			cout << "--------------------------" << endl;
		}
	}


private:
	vector<Sandwich> Sandwiches;
};

int main(){
	//class sandwich with object

	Sandwich number1;
	Sandwich number2;
	Sandwich number3;
	number1.setMayo(5.2);
	number2.setTomatoes(4);
	number3.setCheese(0);
	SandwichTruck truck;
	truck.addSandwich(number1);
	truck.addSandwich(number2);
	truck.addSandwich(number3);
	truck.display();
	system("pause");
}