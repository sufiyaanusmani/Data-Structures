// Sufiyaan Usmani

#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int reverseNum(int n)
{
    while (n != 0)
    {
        st.push(n % 10);
        n = n / 10;
    }

    int rev = 0;
    int i = 1;
    while (!st.empty())
    {
        rev = rev + (st.top() * i);
        i = i * 10;
        st.pop();
    }
    return rev;
}

int main()
{
    int n;
    cin >> n;
    cout << reverseNum(n) << endl;
    return 0;
}