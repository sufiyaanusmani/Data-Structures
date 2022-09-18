// Sufiyaan Usmani

#include <iostream>
using namespace std;

int power(int n, int p)
{
    // base case
    if (p == 0)
    {
        return 1;
    }

    // recursion
    return n * power(n, p - 1);
}

int main()
{
    int n, p;
    cout << "Enter value of n and p: ";
    cin >> n >> p;
    cout << power(n, p) << endl;
    return 0;
}