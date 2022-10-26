#include <iostream>
using namespace std;

void towerOfHanoi(int disks, int a, int b, int c)
{
	if (disks > 0)
	{
		towerOfHanoi(disks - 1, a, c, b);
		cout << "Move from " << a << " to " << c << endl;
		towerOfHanoi(disks - 1, b, a, c);
	}
}

int main()
{
	towerOfHanoi(3, 1, 2, 3);
	return 0;
}
