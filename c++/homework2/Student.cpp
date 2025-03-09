#include "Student.h"
Student::Student(string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
}
Student::Student(string firstName, string lastName, map<string, list<int>> gradesOfSubjects)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->gradesOfSubjects = gradesOfSubjects;
}
bool Student::addSubject(string name, list<int> grades)
{
	try
	{
		this->gradesOfSubjects.insert({ name,grades });
	}
	catch (exception e)
	{
		return false;
	}
	return true;
}
bool Student::removeSubject(string name)
{
	try
	{
		this->gradesOfSubjects.erase(this->gradesOfSubjects.find(name));
	}
	catch (exception e)
	{
		return false;
	}
	return true;
}
bool Student::isScholarshipWorhy(double minimalAvg, double gradeBound)
{
	list<double> avgs = {};
	for (auto subject : this->gradesOfSubjects)
	{
		int count = subject.second.size();
		int sum = 0;
		for (int grade : subject.second)
		{
			sum += grade;
		}
		double avg = (double)(sum) / count;
		if (avg > gradeBound)
		{
			return false;
		}
		avgs.push_back(avg);
	}
	double totalSum = 0;
	int totalCount = avgs.size();
	for (double avg : avgs)
	{
		totalSum += avg;
	}
	double totalAvg = totalSum / totalCount;
	if (totalAvg >= minimalAvg) return false;

	return true;

}