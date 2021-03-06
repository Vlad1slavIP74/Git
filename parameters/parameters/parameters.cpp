// thread.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>

// library for
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;


void DoWork(int a, int b)
{
	sleep_for(chrono::milliseconds(1500));
	cout << "=============\t DoWork\t=============" << endl;
	sleep_for(chrono::milliseconds(1500));
	cout << " A + B = " << a + b << endl;
	sleep_for(chrono::milliseconds(1500));
	cout << "=============\t DoWork finished\t================" << endl;
}


int main()
{
	// створення потоку th й передачу в нього фун-ції DoWork
	
	int a = 5;
	int b = 6;

	thread th(DoWork, a, b);

	//DoWork();
	
	for (int i = 0; true; i++)
	{
		cout << "ID = " << get_id() << "\tMain\t" << i << endl;
		sleep_for(chrono::milliseconds(1000));
	}

	th.join();
	

	return 0;
}

