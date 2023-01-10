// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 1(b)

#include <iostream>
using namespace std;

void print(int n, int previous)
{
	static int diff = 0;
	int num;
	if (n == 0)
	{
		return;
	}
	else
	{
		if (diff == 0)
		{
			cout << previous << "  ";
			n--;
		}
		num = previous + diff;
		cout << num << "  ";
		diff++;
		print(n - 1, num);
	}
}

int main()
{
	int n;
	cout << "Enter number of elements to print in sequence: ";
	cin >> n;
	cout << "\nSequence: ";
	print(n, 1);
	return 0;
}
