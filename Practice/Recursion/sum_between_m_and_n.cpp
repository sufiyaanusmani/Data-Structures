// Sufiyaan Usmani

#include <iostream>
using namespace std;

int sum(int m, int n)
{
    if (n == m)
    {
        return m;
    }
    return n + sum(m, n - 1);
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << sum(m, n);
    return 0;
}