// Sufiyaan Usmani

#include <iostream>
using namespace std;

void decToBin(int n)
{
    if (n <= 1)
    {
        cout << n;
    }
    else
    {
        decToBin(n / 2);
        cout << n % 2;
    }
}

int main()
{
    int n;
    cin >> n;
    decToBin(n);
    return 0;
}