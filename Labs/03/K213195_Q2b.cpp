// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 2(a)

#include <iostream>
using namespace std;

void print2(int, int, int);
void print1(int n, int start, int diff)
{
	// This function is used for adding difference in previous number and printing the number

	// base case
	if (n == 0)
	{
		return;
	}
	else
	{
		if (diff == 0)
		{
			cout << start << "  ";
			n--;
		}
		cout << start + diff << "  ";

		// calling function to update difference
		print2(n - 1, start + diff, diff);
	}
}

void print2(int n, int start, int diff)
{
	// base case
	if (n == 0)
	{
		return;
	}

	// calling print1 function with updated value of difference
	print1(n, start, diff + 1);
}

int main()
{
	int n;
	cout << "Enter number of elements to print in sequence: ";
	cin >> n;
	print1(n, 1, 0);
	return 0;
}
