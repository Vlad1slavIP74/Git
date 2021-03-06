// thread.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
 
void DoWork();

int main() 
{
	thread th(DoWork);

	for (int i = 0; i < 10; i++)
	{
		cout << "Id = " << get_id() << " main " << i
			<< endl;
		sleep_for(chrono::milliseconds(100));
	}

	th.join();
    return 0;
}

void DoWork()
{
	for (int i = 0; i < 10; i++) 
	{
		cout << "Id = " << get_id() << "Do work " << i
			<< endl;
		sleep_for(chrono::milliseconds(200));
	}
}

