// Sufiyaan Usmani

#include <iostream>
using namespace std;

void toh(int n, char from, char to, char aux)
{
    if (n > 0)
    {
        toh(n - 1, from, aux, to);
        cout << from << " to " << to << endl;
        toh(n - 1, aux, to, from);
    }
}

int main()
{
    toh(3, 'A', 'C', 'B');
    return 0;
}