// Sufiyaan Usmani

#include <iostream>
using namespace std;

int rev(int n)
{
    static int num = 0;
    if (n != 0)
    {
        num = (num * 10) + (n % 10);
        rev(n / 10);
    }
    return num;
}

int main()
{
    int n;
    cin >> n;
    cout << rev(n);
    return 0;
}