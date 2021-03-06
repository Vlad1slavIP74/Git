// Copyright_Constructor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class MyClass {

public:
	int *data;

	MyClass(int data) {

		this->Size = data;
		this->data = new int[data];

		for (int i = 0; i < data; i++)
			this->data[i] = i;

		cout << "Constructor  " << this << endl;


	}

	MyClass(const MyClass &other)
	{
		this->Size = other.Size;
		this->data = new int[other.Size];

		for (int i = 0; i < other.Size; i++)
			data[i] = i;

		cout << "Constructor  Copyright " << this << endl;

	}

	MyClass & operator = (const MyClass &other)
	{
		cout << "Operator = " << this << endl;

		this->Size = other.Size;

		if (this->data != nullptr)
			delete[] this->data;

		this->data = new int[other.Size];

		for (int i = 0; i < other.Size; i++)
			this->data[i] = other.data[i];
		return *this;
	}

	~MyClass() {
		delete[] data;
		cout << "Destructor    " << this << endl;
	}
private:
	int Size;
};




int main()
{
	MyClass a(5);

	MyClass b(1);
	MyClass d(2);

	a = b = d;

	return 0;
}

