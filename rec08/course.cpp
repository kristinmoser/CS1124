#include "student.h"
#include "course.h"
#include <string>
#include <vector>

using namespace std;

namespace BrooklynPoly{

	Course::Course(string name): name(name) {};

	void Course::addStudent(Student* someStudent){
		students.push_back(someStudent);
	}
	string Course::getName()const{
		return name;
	}
	void Course::display() const{
		cout << name << ":" << endl;
		for (size_t i = 0; i < students.size(); ++i){
			cout << students[i]->getName() << endl;
		}
	}
	void Course::empty(){
		for (size_t i = 0; i < students.size(); ++i){
			delete students[i];
		}
		students.clear();
	}
}