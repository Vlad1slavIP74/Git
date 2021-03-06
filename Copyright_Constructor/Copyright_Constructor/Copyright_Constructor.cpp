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

		cout << "Constructor  " << this <<  endl;


	}

	MyClass(const MyClass &other)
	{
		this->Size = other.Size;
		this->data = new int[other.Size];

		for (int i = 0; i < other.Size; i++)
			data[i] = i;

		cout << "Constructor  Copyright " << this << endl;
		
	}

	~MyClass() {
		delete[] data;
		cout << "Destructor    " << this <<endl;
	}
private:
	int Size;
};

void Foo(MyClass value) {

	cout << "Function Foo    " << endl;

}

MyClass Foo2() {

	cout << "Function Foo2    " << endl;

	MyClass temp(2);
	return temp;
}

int main()
{
	MyClass a(5);

	MyClass b(a);

	Foo(a);

	Foo2();

    return 0;
}

