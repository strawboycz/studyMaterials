#pragma once
#include <list>
#include <map>
#include <string>
using namespace std;
class Student
{
public:

	string firstName;
	string lastName;
	Student(string firstName, string lastName);
	Student(string firstName, string lastName, map<string, list<int>> gradesOfSubjects);
	bool addSubject(string name, list<int> grades);
	bool removeSubject(string name);
	bool isScholarshipWorhy(double minimalAvg, double gradeBound);
private:
	map<string, list<int>> gradesOfSubjects;

};
