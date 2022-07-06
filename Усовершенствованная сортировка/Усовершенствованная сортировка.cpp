#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
	string name;
	string group;
	double averageScore;
	int salary;
};

void fillStudent(Student& stud)
{
	cout << "Имя >> ";
	cin >> stud.name;
	/*cin.clear();
	cin.ignore();
	getline(cin, stud.name);*/
	cout << "Группа >> ";
	cin >> stud.group;
	cout << "Средний балл >> ";
	cin >> stud.averageScore;
	cout << "Зарплата >> ";
	cin >> stud.salary;
}

void Print(vector<Student> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		cout << "Имя: " << array[i].name << ", группа: " << array[i].group << endl;
	}
}

void ArrayToHeapSalary(Student* array, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		int index = i;

		while (index != 0)
		{
			int parent = (index - 1) / 2;

			if (array[parent].salary >= array[index].salary) break;
			else
			{
				swap(array[parent], array[index]);
				index = parent;
			}
		}
	}
}

void HeapRebuildSalary(Student* array, const int SIZE)
{
	Student res = array[0];
	
	int index = 0;

	while (true)
	{
		int l = 2 * index + 1;
		int r = 2 * index + 2;

		if (l >= SIZE) l = index;
		if (r >= SIZE) r = index;

		if (array[index].salary >= array[l].salary && array[index].salary >= array[r].salary) break;
		else
		{
			int swap_child;
			if (array[l].salary > array[r].salary) swap_child = l;
			else swap_child = r;

			swap(array[index], array[swap_child]);
			index = swap_child;
		}
	}
}

void ArrayToHeapScore(Student* array, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		int index = i;

		while (index != 0)
		{
			int parent = (index - 1) / 2;

			if (array[parent].averageScore >= array[index].averageScore) break;
			else
			{
				swap(array[parent], array[index]);
				index = parent;
			}
		}
	}
}

void HeapRebuildScore(Student* array, const int SIZE)
{
	Student res = array[0];

	int index = 0;

	while (true)
	{
		int l = 2 * index + 1;
		int r = 2 * index + 2;

		if (l >= SIZE) l = index;
		if (r >= SIZE) r = index;

		if (array[index].averageScore >= array[l].averageScore && array[index].averageScore >= array[r].averageScore) break;
		else
		{
			int swap_child;
			if (array[l].averageScore > array[r].averageScore) swap_child = l;
			else swap_child = r;

			swap(array[index], array[swap_child]);
			index = swap_child;
		}
	}
}

void HeapSort(Student* array, const int SIZE, bool situation = true)
{
	if (situation)
	{
		ArrayToHeapSalary(array, SIZE);

		for (int i = SIZE - 1; i > 0; i--)
		{
			swap(array[0], array[i]);

			HeapRebuildSalary(array, i);
		}
	}
	else
	{
		ArrayToHeapScore(array, SIZE);

		for (int i = SIZE - 1; i > 0; i--)
		{
			swap(array[0], array[i]);

			HeapRebuildScore(array, i);
		}
	}
}

int BinarySearch(vector<Student> stud, double score)
{
	int firstIndex = 0;
	int lastIndex = stud.size() - 1;
	while (firstIndex <= lastIndex)
	{
		int middle = (firstIndex + lastIndex) / 2;
		if (stud[middle].averageScore == score) return middle;
		else if (stud[middle].averageScore > score) lastIndex = middle - 1;
		else firstIndex == middle + 1;
	}
	return -1;
}

int main()
{
	system("chcp 1251 > null");
	int size;
	cin >> size;
	Student* array = new Student[size];
	for (int i = 0; i < size; i++)
	{
		fillStudent(array[i]);
	}

	unsigned int minSalary;
	cout << "Минимальная з/п >> ";
	cin >> minSalary;


	vector<Student> resultQueue;
	HeapSort(array, size);
	int index = 0;

	while (array[index].salary < minSalary*2)
	{
		resultQueue.push_back(array[index]);
		index++;
	}
	/
	HeapSort(array, size, 0);
	for (int i = size - 1; i >= 0; i--)
	{
		if (BinarySearch(resultQueue, array[i].averageScore) == -1) resultQueue.push_back(array[i]);
	}

	Print(resultQueue);
	delete[] array;
}