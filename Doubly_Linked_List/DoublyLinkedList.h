#pragma once
#include <iostream>
#include <exception>
using namespace std;


template <class T>
struct Node
{
	Node(T value)
	{
		this->value = value;
		Next = nullptr;
	}
	T value;
	Node<T>* Next = nullptr;
	Node<T>* Prev = nullptr;
};

template <class T>
class DoublyLinkedList
{
	Node<T>* Head;
	int count;

public:
	
	DoublyLinkedList()
	{
		Head = nullptr;
		count = 0;
	}
	~DoublyLinkedList()
	{
		if (Head)
		{
			Node<T>* Temp = Head;
			while (Head)
			{
				Temp = Head;
				Head = Head->Next;
				delete Temp;
			}
		}
	}

	void Add(T value)
	{
		Node<T>* newnode = new Node<T>(value);

		if (!Head)
		{
			Head = newnode;
			count++;
			return;
		}


		newnode->Next = Head;
		Head->Prev = newnode;
		Head = newnode;
		count++;
	}

	int GetCount()
	{
		return count;
	}



	void PrintAllNodes()
	{
		Node<T>* temp = Head;

		while (temp)
		{
			cout << temp->value << " ";
			temp = temp->Next;
		}
	}

	bool Delete(int index)
	{
		if (index < 0 || index >= count || (!Head))
		{
			return false;
		}

		//Check if the index is the first element in the list
		if (index == 0)
		{
			Node<T>* temp = Head;

			//if there is items in the list
			if (Head->Next != nullptr)
			{
				Head->Next->Prev = nullptr;
			}
			Head = Head->Next;
			count--;
			delete temp;
			return true;
		}
		
		int Counter = 0;

		Node<T>* temp = Head;
		//loop until find the item to delete
		while (temp && Counter != index)
		{
			temp = temp->Next;
			Counter++;
		}


		if (!temp)
		{
			return false;
		}
		
		Node<T>* t = temp;
		
		//checking if it is the last item in the list
		if (t->Next == nullptr)
		{
			temp->Prev->Next = temp->Next;
			count--;
			delete t;
			return true;
		}


		//when you reach here it means the item you want to delete is in the middle of the list
		//and it has next and prev
		temp->Prev->Next = temp->Next;
		temp->Next->Prev = temp->Prev;

		count--;
		delete t;
		return true;

	}

	bool InsertAt(int index, T value)
	{
		if (index < 0 || index > count)
		{
			return false;
		}

		


		Node<T>* newNode = new Node<T>(value);
		if (!Head)
		{
			Head = newNode;
			count++;
			return true;
		}

		//insert at beginning
		if (index == 0)
		{
			newNode->Next = Head;
			Head->Prev = newNode;
			Head = newNode;
			count++;
			return true;
		}

		


		Node<T>* Temp = Head;

		int Counter = 0;

		//Adding 1 to Counter to stop at last node in the list becuase i don't want to be out of range
		if (index == count)
			Counter++;

		while (Temp && Counter != index)
		{
			Temp = Temp->Next;
			Counter++;
		}
		
		if (!Temp)
		{
			return false;
		}
		//Insert at end
		if (index == count)
		{
			Temp->Next = newNode;
			newNode->Prev = Temp;
			count++;
			return true;
		}
		
		//at this moment the index you want to delete is in the middle of list and it has prev and next.
		newNode->Next = Temp;
		newNode->Prev = Temp->Prev;
		Temp->Prev->Next = newNode;
		Temp->Prev = newNode;

		count++;
		return true;
	}

	int Search(T value)
	{
		if (Head)
		{
			int Counter = 0;
			Node<T>* temp = Head;
			while (temp)
			{
				if (temp->value == value)
				{
					return Counter;
				}
				temp = temp->Next;
				Counter++;
			}
			return -1;
		}

	}
};