#include "Computer.h"

#include <iostream>


Computer::Computer(const string& name, const string& cpu, const string& gpu)
	: name(name),
	CPU(cpu),
	GPU(gpu)
{
}

string Computer::getName()
{
	return name;
}

string Computer::getCPU()
{
	return CPU;
}

string Computer::getGPU()
{
	return GPU;
}

void Computer::printParameters() 
{
	cout << "Name: " << this->name << " CPU: " << this->CPU << " GPU: " << this->GPU << '\n';
}