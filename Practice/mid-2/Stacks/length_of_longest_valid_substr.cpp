// Sufiyaan Usmani

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int getLength(string str)
{
    stack<char> st;
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            st.push('(');
        }
        else if (str[i] == ')')
        {
            if (!st.empty())
            {
                st.pop();
                count += 2;
            }
        }
    }
    return count;
}

int main()
{
    string str;
    cin >> str;
    cout << getLength(str) << endl;
    return 0;
}