// Sufiyaan Usmani
// check if a number is prime

#include <iostream>
using namespace std;

bool isPrime(int start, int n)
{
    if (start == n)
    {
        return true;
    }
    if (n % start == 0)
    {
        return false;
    }
    isPrime(start + 1, n);
}

int main()
{
    int n;
    cin >> n;
    cout << isPrime(2, n) << endl;
    return 0;
}