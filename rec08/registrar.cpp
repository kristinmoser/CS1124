#include "student.h"
#include "course.h"
#include "registrar.h"
#include <string>
#include <vector>

namespace BrooklynPoly{
	void Registrar::addCourse(std::string name){
		Course* ACourse = new Course(name);
		courses.push_back(ACourse);
	}
	void Registrar::addStudent(std::string name){
		Student* AStudent = new Student(name);
		students.push_back(AStudent);
	}
	void Registrar::enrollStudentInCourse(std::string studentName, std::string courseName){
		for (Student* studentptr : students){
			if (studentptr->getName() == studentName){
				for (Course* courseptr : courses){
					if (courseptr->getName() == courseName){
						courseptr->addStudent(studentptr);
						studentptr->addCourse(courseptr);
					}
				}
			}
		}
	}
	void Registrar::cancelCourse(std::string name){
		for (size_t i = 0; i < courses.size()-1; ++i){
			if (courses[i]->getName() == name){
				for (Student* studentptr : students){
					studentptr->dropCourse(courses[i]);
				}
				courses[i] = nullptr;
				courses.erase(courses.begin() + i);
			}
		}
	}
	void Registrar::printReport(){
		for (size_t i = 0; i < courses.size(); ++i){
			courses[i]->display();
		}
	}
	void Registrar::purge(){
		for (size_t i = 0; i < students.size(); ++i){
			delete students[i];
		}
		students.clear();
		for (size_t i = 0; i < courses.size(); ++i){
			delete courses[i];
		}
		courses.clear();
	}

	Student* Registrar::findStudent(std::string name)const{
		for (size_t i = 0; i < students.size(); ++i){
			if (students[i]->getName() == name){
				return students[i];
			}
		}
		return nullptr;
	}
	Course* Registrar::findCourse(std::string name)const{
		for (size_t i = 0; i < courses.size(); ++i){
			if (courses[i]->getName() == name){
				return courses[i];
			}
		}
		return nullptr;
	}
}