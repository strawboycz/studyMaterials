#pragma once
#include <list>
using namespace std;
#include "Student.h"

class Classroom
{
public:
	list<Student> students;
	Classroom(list<Student> students);
	Classroom();
	void addStudent(Student student);
	void printStudentsWithScholarship(double minimalAvg, double gradeBound);
};
