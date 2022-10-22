// Sufiyaan Usmani

#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^')
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
        return -1;
    }
}

string infixToPostfix(stack<char> st, string infix)
{
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((st.top() != '(') && (!st.empty()))
            {
                postfix += st.top();
                st.pop();
            }
            if (st.top() == '(')
            {
                st.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (st.empty())
            {
                st.push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > precedence(st.top()))
                {
                    st.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(st.top())) && st.top() == '^')
                {
                    st.push(infix[i]);
                }
                else
                {
                    while ((!st.empty()) && (precedence(infix[i]) <= precedence(st.top())))
                    {
                        postfix += st.top();
                        st.pop();
                    }
                    st.push(infix[i]);
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

int main()
{
    string infix_exp, postfix_exp;
    cout << "Enter a Infix Expression :" << endl;
    cin >> infix_exp;
    stack<char> stack;
    cout << "INFIX EXPRESSION: " << infix_exp << endl;
    postfix_exp = infixToPostfix(stack, infix_exp);
    cout << "\nPOSTFIX EXPRESSION: " << postfix_exp;

    return 0;
}