// Sufiyaan Usmani

#include <iostream>
using namespace std;

void printNReversed(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << "  ";
    printNReversed(n - 1);
}

int main()
{
    int n;
    cin >> n;
    printNReversed(n);
    return 0;
}