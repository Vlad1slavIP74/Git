// shellSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillArray(int *arr, int size);

void print(int* arr, int size);

void shellSort(int *arr, int size);

int main()
{
	int size;

	cout << "Enter size of array" << endl;
	cin >> size;

	int *arr = new int[size];

	fillArray(arr, size);

	print(arr, size);

	shellSort(arr, size);

	cout << "Array after sort: " << endl;

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

void shellSort(int *arr, int size) {
	int step = 1;

	while (step < size / 3) {
		step = step * 3 + 1;
	}

	while (step >= 1) {
		for (int j = step; j < size; j++) {
			
			int key = arr[j];
			int i = j - step;

			while (i >= 0 && arr[i] > key) {
				arr[i + step] = arr[i];
				i -= step;
			}
			arr[i + step] = key;
		}
		step = (step - 1) / 3;
	}
}