// Sufiyaan Usmani

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
    if (n > 0)
    {
        towerOfHanoi(n - 1, fromRod, auxRod, toRod);
        cout << "Move disk from " << fromRod << " to " << toRod << endl;
        towerOfHanoi(n - 1, auxRod, toRod, fromRod);
    }
}

int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}