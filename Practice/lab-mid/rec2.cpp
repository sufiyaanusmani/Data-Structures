// Sufiyaan Usmani

#include <iostream>
using namespace std;

bool isPrime(int n)
{
    static int i = 2;
    if (i == n)
    {
        return true;
    }
    if (n % i == 0)
    {
        return false;
    }
    i++;
    return isPrime(n);
}

int main()
{
    cout << isPrime(57) << endl;
    return 0;
}