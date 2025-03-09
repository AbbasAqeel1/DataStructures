#include <iostream>
#include "ArrayList.h"
#include <string>
using namespace std;

void main()
{
	ArrayList<string> A;

	for (int i = 0;i < 10;i++)
	{
		string value = to_string(i);
		A.Add(value);
	}

	A[4] = "17.11";

	cout << "Array items:\n";
	for (int i = 0;i < A.GetSize();i++)
	{
		cout << A[i] << endl;
	}

	cout << "\n\nArray1 Size: " << A.GetSize() << endl;
	cout << "Array1 Capacity: " << A.GetCapacity() << endl;

	int Num2 = 400;
	int Result = Num2 + stoi(A[3]);

	cout << "\n\nafter Convert string to int: " << Result << endl;


}