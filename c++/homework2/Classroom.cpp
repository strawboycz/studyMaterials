#include "Classroom.h"

#include <iostream>

Classroom::Classroom(list<Student> students)
{
	this->students = students;
}
Classroom::Classroom()
{
}
void Classroom::addStudent(Student student)
{
	this->students.push_back(student);
}
void Classroom::printStudentsWithScholarship(double minimalAvg, double gradeBound)
{
	for (Student student : this->students)
	{
		if (student.isScholarshipWorhy(minimalAvg,gradeBound))
		{
			cout << student.firstName + " " + student.lastName + "\n";
		}
	}
}

