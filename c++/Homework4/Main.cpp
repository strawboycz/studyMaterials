#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main(int argc, char* argv[])
{
	DynamicArray array1 = DynamicArray();
	DynamicArray array2 = DynamicArray(5);
	int arr[] = {1, 2, 3, 4, 5};
	DynamicArray array3 = DynamicArray(arr,5);
	cout << "Array1: " << array1.toString() << endl;
	cout << "Array2: " << array2.toString() << endl;
	cout << "Array3: " << array3.toString() << endl;

	array3.add(6);
	array3.add(7);
	array3.add(8);
	array3.add(9);
	array3.add(10);
	array3.add(11);
	array3.add(12);


	cout << array3.toString() << endl;

	array3.removeAt(9);

	cout << array3.toString() << endl;

	return 0;
}
