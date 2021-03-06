// thread.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>

// library for
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;


void Decrement(int &a, int &b)
{
	sleep_for(chrono::milliseconds(1500));

	cout << "=============\t DoWork\t=============" << endl;

	sleep_for(chrono::milliseconds(1500));

	a *=  2;

	b += b + 1;

	sleep_for(chrono::milliseconds(1500));

	cout << "=============\t DoWork finished\t================" << endl;

}


int main()
{
	// створення потоку th й передачу в нього фун-ції DoWork

	int a = 5;
	int b = 6;

	thread th(Decrement, ref(a), ref(b));

	

	for (int i = 0; i < 10; i++)
	{
		cout << "ID = " << get_id() << "\tMain\t" << i << endl;
		sleep_for(chrono::milliseconds(300));
	}

	th.join();

	cout << "A after function " << a << endl;

	cout << "B after function " << b << endl;

	return 0;
}

