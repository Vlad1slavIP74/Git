// Thread_with_parameters.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;

void Sum(int a, int b);

int main()
{
	thread th(Sum, 4, 45);

	for (int i = 0; i < 10; i++)
	{
		cout << "ID of thread " << get_id() << "\tmain" <<
			endl;
		sleep_for(chrono::milliseconds(1000));
	}

	th.join();
    return 0;
}

void Sum(int a, int b)
{

	sleep_for(chrono::milliseconds(4000));

	cout << "===========\t Do work started \t =========="
		<< endl;
	sleep_for(chrono::microseconds(1500));

	cout << "Sum is " << a + b << endl;

	sleep_for(chrono::microseconds(1500));

	cout << "===========\t Do work finished \t =========="
		<< endl;
	sleep_for(chrono::microseconds(1500));
}
