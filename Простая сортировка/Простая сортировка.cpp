#include <iostream>
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

void ChoiceSort(vector<Student>& array, bool choice = true)
{
	if (choice)
	{
		int min_index;
		int count = 0;
		for (int i = 0; i < array.size(); i++)
		{
			min_index = i;
			for (int j = i + 1; j < array.size(); j++)
			{
				if (array[min_index].salary > array[j].salary) min_index = j;
			}

			if (min_index != i)
			{
				swap(array[i], array[min_index]);
			}
		}
	}
	else
	{
		int min_index;
		int count = 0;
		for (int i = 0; i < array.size(); i++)
		{
			min_index = i;
			for (int j = i + 1; j < array.size(); j++)
			{
				if (array[min_index].averageScore < array[j].averageScore) min_index = j;
			}

			if (min_index != i)
			{
				swap(array[i], array[min_index]);
			}
		}
	}
}

int BinarySearch(vector<Student> stud, string name)
{
	for (int i = 0; i < stud.size(); i++)
	{
		if (stud[i].name == name) return 0;
	}
	return 1;
}

int main()
{
	system("chcp 1251 > null");
	int size;
	cin >> size;
	vector<Student> array (size);
	for (int i = 0; i < size; i++)
	{
		fillStudent(array[i]);
	}

	unsigned int minSalary;
	cout << "Минимальная з/п >> ";
	cin >> minSalary;

	ChoiceSort(array);

	vector<Student> resultQueue;
	
	int index = 0;
	while (array[index].salary < minSalary * 2)
	{
		resultQueue.push_back(array[index]);
		index++;
	}

	ChoiceSort(array, false);
	for (int i = 0; i < array.size(); i++)
	{
		if (BinarySearch(resultQueue, array[i].name)) resultQueue.push_back(array[i]);
	}

	Print(resultQueue);
}
