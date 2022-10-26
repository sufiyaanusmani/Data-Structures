// Sufiyaan Usmani

#include <iostream>
using namespace std;

int fibonacci(int first, int second, int n)
{
    if (n == 1)
    {
        return first;
    }
    else if (n == 2)
    {
        return second;
    }
    else
    {
        return fibonacci(first, second, n - 1) + fibonacci(first, second, n - 2);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(1, 1, n);
    return 0;
}