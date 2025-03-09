#pragma once
#include <iostream>
#include <exception>
using namespace std;

template <class T>
class ArrayList
{
	int size;
	int capacity;
	T* InternalArray;

	void ResizeArray()
	{
		T* temp = new T[capacity+10];
			
		for (int i = 0;i < size;i++)
		{
			temp[i] = InternalArray[i];
		}

		delete[] InternalArray;
		InternalArray = temp;
		capacity += 10;
	}

public:
	ArrayList(int capacity = 10)
	{
		this->capacity = capacity;
		size = 0;
		InternalArray = new T[capacity];
	}

	ArrayList(T array[],int arraySize)
	{
		size = arraySize;
		capacity = size + 10;
		


		InternalArray = new T[capacity];
		for (int i = 0;i < arraySize;i++)
		{
			InternalArray[i] = array[i];
		}
	}


	void Add(T Item)
	{
		if (size >= capacity)
		{
			cout << "\nResize Array func called\n";
			ResizeArray();
		}


		InternalArray[size] = Item;
		size++;
	}
	bool Delete(int index)
	{
		if (index < 0 || index >= size)
			return false;

		for (int i = index;i < size -1;i++)
		{
			InternalArray[i] = InternalArray[i + 1];
		}
		InternalArray[size - 1] = 0;
		size--;
		return true;
	}
	

	T& operator[](int Index)
	{
		if (Index >= size || Index < 0)
		{
			throw "Error, index out of range.";
		}
		return InternalArray[Index];
	}

	int GetSize()
	{
		return size;
	}

	int GetCapacity()
	{
		return capacity;
	}

	
	bool InsertAt(int index,T value)
	{
		if (index < 0 || index > size || (size ==0))
		{
			return false;
		}

		if (size >= capacity)
		{
			ResizeArray();
		}

		for (int i = size;i > index;i--)
		{
			InternalArray[i] = InternalArray[i - 1];
		}
		InternalArray[index] = value;
		size++;
		return true;
	}
};