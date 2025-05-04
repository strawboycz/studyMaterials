#pragma once
#include <string>
using namespace std;
class Building
{
public:
	Building(string name,string number);
	virtual string toString() = 0;
	string getName() ;
	void setName(string name);
	string getNumber() ;
	void setNumber(string number);

protected:
	string name;
	string number;
};
