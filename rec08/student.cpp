#include "student.h"
#include "course.h"
#include <string>
#include <vector>

namespace BrooklynPoly{
	Student::Student(std::string name) : name(name){}
	void Student::addCourse(Course* ACourse){
		courses.push_back(ACourse);
	}
	std::string Student::getName()const{
		return name;
	}
	void Student::dropCourse(Course* courseptr){
		for (size_t i = 0; i < courses.size(); ++i){
			if (courses[i] == courseptr){
				delete courses[i];
				courses[i] = nullptr;
				courses.erase(courses.begin() + i);
			}
		}
	}
}