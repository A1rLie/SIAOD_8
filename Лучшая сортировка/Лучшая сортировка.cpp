#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>

using namespace std;

void UserFill(int* array, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cin >> array[i];
	}
}

void SpecFill(int* array, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = i;
	}
}

void AutoFill(int* array, const int SIZE)
{
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 200;
	}
}

void Print(int* array, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void Merge(int* target, int* array1, const int SIZE1, int* array2, const int SIZE2, int& count)
{
	int indexArr1 = 0;
	int indexArr2 = 0;
	int indexTarget = 0;

	count++;
	while (indexArr1 < SIZE1 && indexArr2 < SIZE2)
	{
		count++;
		if (array1[indexArr1] <= array2[indexArr2])
		{
			target[indexTarget] = array1[indexArr1];
			indexArr1++;
		}
		else
		{
			target[indexTarget] = array2[indexArr2];
			indexArr2++;
		}
		indexTarget++;
	}

	count++;
	while (indexArr1 < SIZE1)
	{
		target[indexTarget] = array1[indexArr1];
		indexArr1++;
		indexTarget++;
	}

	count++;
	while (indexArr2 < SIZE2)
	{
		target[indexTarget] = array2[indexArr2];
		indexArr2++;
		indexTarget++;
	}
}

void MergeSort(int* target, const int SIZE, int& count)
{
	count++;
	if (SIZE < 2) return;

	int midIndex = SIZE / 2;

	int* arrLeft = new int[midIndex];
	count++;
	for (int i = 0; i < midIndex; i++)
	{
		arrLeft[i] = target[i];
	}

	int* arrRight = new int[SIZE - midIndex];
	count++;
	for (int i = midIndex; i < SIZE; i++)
	{
		arrRight[i - midIndex] = target[i];
	}

	MergeSort(arrLeft, midIndex, count);
	MergeSort(arrRight, SIZE - midIndex, count);

	Merge(target, arrLeft, midIndex, arrRight, SIZE-midIndex, count);
	delete[] arrLeft;
	delete[] arrRight;
}



int main()
{
	int size;
	cin >> size;

	int count = 0;
	int* arr = new int[size];

	SpecFill(arr, size);
	//cout << "Sorted: ";
	//Print(arr, size);
	int start = clock();
	//cout << "\nUnsorted: ";
	MergeSort(arr, size, count);
	//Print(arr, size);
	cout << "Time: " << (clock() - start) << "\nOperations: " << count;
}

