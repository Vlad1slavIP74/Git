// QuickSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillArray(int *arr, int size);

void print(int* arr, int size);

void quickSort(int* arr, int size, int left = 0);

int main()
{
	int size;

	cout << "Enter size of array" << endl;
	cin >> size;

	int *arr = new int[size];

	fillArray(arr, size);

	print(arr, size);

	quickSort(arr, size - 1);

	cout << "Array after sort" << endl;

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

void quickSort(int * arr, int size, int left)
{
	int i = left;
	int j = size;

	int tmp;

	int pivot = arr[(left + size) / 2];

	while(i <= j)
	{
		while (arr[i] < pivot) 
			i++;
		
		while (arr[j] > pivot)
			j--;

		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j)
		quickSort(arr, j, left);
	if (i < size)
		quickSort(arr, size, i);
}
