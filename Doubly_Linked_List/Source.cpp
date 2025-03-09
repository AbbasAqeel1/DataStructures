#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

void main()
{

	DoublyLinkedList<int> DL1;

	for (int i = 1;i <= 10;i++)
	{
		DL1.Add(i);
	}

	cout << "Items before insertion: \n";
	DL1.PrintAllNodes();



	int index = DL1.Search(5);

	if (index)
	{
		cout << "\n" << index << " found in the list\n";
	}
	else
	{
		cout << "\n" << index << " not found in the list\n";
	}

	if (DL1.Delete(index))
	{
		cout << "\nitem deleted Successfully\n";
	}
	else
	{
		cout << "\nitem was not deleted Successfully\n";
	}

	DL1.PrintAllNodes();
	cout << "\n\nList Items are: " << DL1.GetCount() << endl;



}