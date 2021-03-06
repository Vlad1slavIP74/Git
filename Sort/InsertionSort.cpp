// InsertionSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillArray(int *arr, int size);

void print(int* arr, int size);

void insertion(int *arr, int size);

int main()
{
	int size;

	cout << "Enter size of array" << endl;
	cin >> size;

	int *arr = new int[size];

	fillArray(arr, size);

	print(arr, size);

	insertion(arr, size);

	cout << "After sort " << endl;

	print(arr, size);

    return 0;
}

void fillArray(int *arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 198 - 99;
	}
}

void print(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insertion(int * arr, int size)
{
	for (int j = 1; j < size; j++) {
		int key = arr[j];
		int i = j - 1;

		while (i >= 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}

}
