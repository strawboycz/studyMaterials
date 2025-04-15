#pragma once
#include <string>

#include "Electronics.h"
using namespace std;
class  Computer : public Electronics
{
public:
	Computer(const string& name, const string& cpu, const string& gpu);
	string getName();
	string getCPU();
	string getGPU();
	void printParameters() override;
private:
	string name;
	string CPU;
	string GPU;

};
