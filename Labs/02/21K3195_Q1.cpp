// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 1

#include <iostream>
#define SIZE 3
using namespace std;

bool isIdentity(int arr[SIZE][SIZE], int size)
{
	bool flag = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j && arr[i][j] != 1)
			{ // checking diagnols
				flag = false;
				break;
			}
			else if (i != j && arr[i][j] != 0)
			{ // checking positions other than diagnols
				flag = false;
				break;
			}
		}
	}
	return flag;
}

int main()
{
	int arr[SIZE][SIZE] = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};

	// checking identity matrix
	if (isIdentity(arr, SIZE) == true)
	{
		cout << "IT IS AN IDENTITY MATRIX" << endl;
	}
	else
	{
		cout << "IT IS NOT AN IDENTITY MATRIX" << endl;
	}

	return 0;
}
