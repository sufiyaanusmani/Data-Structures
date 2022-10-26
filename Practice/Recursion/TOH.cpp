// Sufiyaan Usmani

#include <iostream>
using namespace std;

void TOH(int n, char from, char to, char aux)
{
    if (n > 0)
    {
        TOH(n - 1, from, aux, to);
        cout << "Move disk from " << from << " to " << to << endl;
        TOH(n - 1, aux, to, from);
    }
}

int main()
{
    int n;
    cin >> n;

    TOH(n, 'A', 'C', 'B');
    return 0;
}