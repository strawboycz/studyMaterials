#include <iostream>
#include "Set.h"
using namespace std;
int main(int argc, char* argv[])
{
	Set *set1 = new Set(5);
	set1->push(1);
	set1->push(1);
	set1->push(2);
	set1->push(3);
	set1->push(4);
	set1->push(5);
	set1->push(6);
	Set *set2 = new Set(5);
	set2->push(1);
	set2->push(2);
	set2->push(3);
	set2->push(6);
	set2->push(7);
	cout << "Set1: " << set1->toString();
	cout << "Set2: " << set2->toString();
	cout << "Union: " << set1->getUnion(set2)->toString();
	cout << "Complemet: " << set1->getComplement(set2)->toString();
}
