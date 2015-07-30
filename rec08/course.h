#ifndef COURSE_H
#define COURSE_H

#include<string>
#include<vector>
#include<iostream>
namespace BrooklynPoly{
	class Student;
	class Course{
	public:
		Course(std::string name);
		void addStudent(Student* someStudent);
		std::string getName() const;
		void display() const;
		void empty();
	private:
		std::string name;
		std::vector<Student*> students;
	};
}

#endif