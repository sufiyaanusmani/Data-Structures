// Sufiyaan Usmani
// Number of alphabet

#include <iostream>
using namespace std;

void print(int n)
{
    switch (n)
    {
    case 0:
        cout << "Zero ";
        break;
    case 1:
        cout << "One ";
        break;
    case 2:
        cout << "Two ";
        break;
    case 3:
        cout << "Three ";
        break;
    case 4:
        cout << "Four ";
        break;
    case 5:
        cout << "Five ";
        break;
    case 6:
        cout << "Six ";
        break;
    case 7:
        cout << "Seven ";
        break;
    case 8:
        cout << "Eight ";
        break;
    case 9:
        cout << "Nine ";
        break;
    }
}

void say(int n)
{
    int num;
    if (n == 0)
    {
        return;
    }
    num = n % 10;
    say(n / 10);
    print(num);
}

int main()
{
    int n;
    cin >> n;
    say(n);
    return 0;
}