// Sufiyaan Usmani

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (st.top() != '(' && !st.empty())
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(ch))
        {
            if (st.empty())
            {
                st.push(ch);
            }
            else
            {
                if (precedence(ch) > precedence(st.top()))
                {
                    st.push(ch);
                }
                else if ((precedence(ch) == precedence(st.top())) && (ch == '^'))
                {
                    while (precedence(st.top()) == precedence(ch))
                    {
                        postfix += st.top();
                        st.pop();
                    }
                    st.push(ch);
                }
                else if (precedence(ch) == precedence(st.top()))
                {
                    st.push(ch);
                }
                else
                {
                    while (!st.empty() && (precedence(ch) < precedence(st.top())))
                    {
                        postfix += st.top();
                        st.pop();
                    }
                    st.push(ch);
                }
            }
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());

    // converting ( to ) and  ) to (
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    string result = infixToPostfix(infix);
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    cout << "Prefix: " << infixToPrefix(infix) << endl;
    return 0;
}