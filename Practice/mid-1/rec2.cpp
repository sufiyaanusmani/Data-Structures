// Sufiyaan Usmani

#include <iostream>
using namespace std;

int count(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return (n % 2) + count(n / 2);
}

int main()
{
    int n;
    cin >> n;
    cout << count(n) << endl;
    return 0;
}