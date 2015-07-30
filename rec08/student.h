#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<vector>


namespace BrooklynPoly
{
	class Course;
	class Student{
	public:
		Student(std::string name);
		void addCourse(Course* ACourse);
		std::string getName()const;
		void dropCourse(Course* courseptr);
	private:
		std::string name;
		std::vector<Course*> courses;
	};
}
#endif