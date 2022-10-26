// Sufiyaan Usmani
// Tower of Hanoi

#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char from, char to, char aux)
{
    if (n > 0)
    {
        TowerOfHanoi(n - 1, from, aux, to);
        cout << "Move disk from " << from << " to " << to << endl;
        TowerOfHanoi(n - 1, aux, to, from);
    }
}

int main()
{
    int n;
    cin >> n;
    TowerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}