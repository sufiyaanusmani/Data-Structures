// Sufiyaan Usmani

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (st.top() != str[i])
        {
            return false;
        }
        st.pop();
    }
    return true;
}

int main()
{
    string str;
    cin >> str;
    cout << (isPalindrome(str) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}