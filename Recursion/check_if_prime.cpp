// Sufiyaan Usmani

#include <iostream>
using namespace std;

int isPrime(int n)
{
    static int i = 2;
    // base case
    if (i == n)
    {
        return true;
    }
    if (n % i == 0)
    {
        return false;
    }
    i++;
    isPrime(n);
}

int main()
{
    int n;
    cin >> n;
    cout << isPrime(n);
    return 0;
}