// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 5(b)

#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
	if ((x < n) && (y < n) && arr[x][y] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ratInMaze(int **arr, int x, int y, int n, int **solutionArr)
{
	if ((x == n - 1) && (y == n - 1))
	{
		solutionArr[x][y] = 1;
		return true;
	}

	if (isSafe(arr, x, y, n))
	{
		solutionArr[x][y] = 1;

		if (ratInMaze(arr, x + 1, y, n, solutionArr))
		{
			return true;
		}
		if (ratInMaze(arr, x, y + 1, n, solutionArr))
		{
			return true;
		}
		solutionArr[x][y] = 0;
		return false;
	}
	return false;
}

void print(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cout << "Enter size of maze: ";
	cin >> n;

	int **arr, **solutionArr;
	arr = new int *[n];
	solutionArr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		solutionArr[i] = new int[n];
	}

	cout << "Enter path of maze:" << endl;
	// Inputting values
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	// Initializing solutionArr
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			solutionArr[i][j] = 0;
		}
	}

	if (ratInMaze(arr, 0, 0, n, solutionArr))
	{
		cout << "\nPATH: " << endl;
		print(solutionArr, n);
	}
	else
	{
		cout << "\nThis maze can not be solved" << endl;
	}

	// deallocating
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
		delete[] solutionArr[i];
	}
	delete[] arr;
	delete[] solutionArr;
	return 0;
}
