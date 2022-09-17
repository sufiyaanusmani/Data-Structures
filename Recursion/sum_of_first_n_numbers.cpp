// Sufiyaan Usmani
// Sum of first n numbers

#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + sum(n - 1);
    }
}

int main()
{
    cout << "Enter value of n: ";
    int n;
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}