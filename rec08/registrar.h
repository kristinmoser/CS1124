#ifndef REGISTRAR
#define REGISTRAR

#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly{
	class Student;
	class Course;
	class Registrar{
	public:
		void addCourse(std::string name);
		void addStudent(std::string name);
		void enrollStudentInCourse(std::string studentName, std::string courseName);
		void cancelCourse(std::string name);
		void printReport();
		void purge();
	private:
		std::vector<Student*> students;
		std::vector<Course*> courses;
		Student* findStudent(std::string name)const;
		Course* findCourse(std::string name)const;
	};
}
#endif