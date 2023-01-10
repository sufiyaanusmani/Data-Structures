// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 4

#include <iostream>
#define SIZE 5
using namespace std;

class Friends
{
public:
	bool (*arr)[SIZE];
	int size;

	Friends(bool a[SIZE][SIZE], int size) : arr(a), size(size)	// using initilizer list as said in question
	{
	}

	// main implementation of Safe Array
	bool isSafe(int index)
	{
		if (index < 0 || index >= size)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void display()
	{
		cout << "    0   1   2   3   4" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i << "   ";
			for (int j = 0; j < size; j++)
			{
				if (arr[i][j] == true)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
				cout << "   ";
			}
			cout << endl;
		}
	}

	void commonFriends(int person1, int person2)
	{
		bool flag = false;

		cout << "Common friends: ";
		for (int j = 0; j < 5; j++)
		{
			if (arr[person1][j] == true && arr[person2][j] == true)
			{
				cout << j << "  ";
				flag = true;
			}
		}
		if (flag == false)
		{
			cout << "Person " << person1 << " and " << person2 << " have no common friends" << endl;
		}
	}
};

int main()
{
	bool arr[SIZE][SIZE] = {
		{false, true, false, true, true},
		{true, false, true, false, true},
		{false, true, false, false, false},
		{true, false, false, false, true},
		{true, true, false, true, false}};

	Friends obj(arr, SIZE);
	// displaying 2D array
	obj.display();

	// Finding common friends
	int person1, person2;
	cout << "\nEnter number of person 1 (0-4): ";
	cin >> person1;
	cout << "Enter number of person 2 (0-4): ";
	cin >> person2;

	// checking if entered numbers lies in correct index
	if (obj.isSafe(person1) && obj.isSafe(person2))
	{
		obj.commonFriends(person1, person2);
	}
	else
	{
		cout << "Error: Invalid index" << endl;
	}
}
