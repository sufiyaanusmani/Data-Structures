// Sufiyaan Usmani

#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &st)
{
    stack<int> temp;
    while (!st.empty())
    {
        int data = st.top();
        st.pop();
        if (temp.empty())
        {
            temp.push(data);
        }
        else
        {
            while (!temp.empty() && data < temp.top())
            {
                st.push(temp.top());
                temp.pop();
            }
            temp.push(data);
        }
    }
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}

int main()
{
    stack<int> input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);

    // This is the temporary stack
    sortStack(input);
    cout << "Sorted numbers are:\n";

    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
}