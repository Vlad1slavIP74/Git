// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream> 
using namespace std;
const int x = 5;
void main() {
	int x[x];
	int y = sizeof(x) / sizeof(int);
	cout << y;
}