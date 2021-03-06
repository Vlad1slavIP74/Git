// thread.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>

// library for
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;


void DoWork()
{
	for (int i = 0; i < 10; i++) {
		cout << "ID = " << get_id() << "\tDowork\t" << i << endl;
		sleep_for(chrono::milliseconds(500));
	}
}

void pest()
{
	int i = 0;
	while (i < 13) {
		cout << "ID = "<< get_id() << "\tЛось\t" << i << endl;
		sleep_for(chrono::milliseconds(200));
		i++;
	}
}

int main()
{
	// створення потоку th й передачу в нього фун-ції DoWork
	thread th(DoWork);

	thread t(pest);

	//DoWork();

	for (int i = 0; i < 10; i++)
	{
		cout << "ID = " << get_id() <<"\tMain\t" << i << endl;
		sleep_for(chrono::milliseconds(1000));
	}

	th.join();
	t.join();

    return 0;
}

