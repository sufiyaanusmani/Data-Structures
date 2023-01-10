// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 2

#include <iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	void input()
	{
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter Year: ";
		cin >> year;
	}

	void display()
	{
		cout << day << " / " << month << " / " << year << endl;
	}

	friend void selectionSort(Date[], int n); // this will sort array of objects
};

void selectionSort(Date date[], int n)
{
	int minIndex;
	Date temp;
	for (int i = 0; i < n - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (date[j].year < date[minIndex].year)
			{
				minIndex = j;
			}
		}
		temp = date[i];
		date[i] = date[minIndex];
		date[minIndex] = temp;
	}
}

int main()
{
	Date date[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "-- DATE " << i + 1 << " --" << endl;
		date[i].input();
		cout << endl;
	}

	cout << "\nBEFORE SORTING" << endl;

	for (int i = 0; i < 5; i++)
	{
		date[i].display();
	}

	selectionSort(date, 5);

	cout << "\nAFTER SORTING" << endl;

	for (int i = 0; i < 5; i++)
	{
		date[i].display();
	}
	return 0;
}
