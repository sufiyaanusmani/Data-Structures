// Sufiyaan Usmani

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    while (!q.empty())
    {
        cout << q.front() << "  ";
        q.pop();
    }
    cout << endl;
}

void reverse(queue<int> &q, int k, int size)
{
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        cout << "Pushing: " << q.front() << endl;
        st.push(q.front());
        q.pop();
    }
    for (int i = 0; i < k; i++)
    {
        cout << "Popping: " << st.top() << endl;
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < size - k; i++)
    {
        cout << "Enqueuing: " << q.front() << endl;
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < size; i++)
    {
        cout << q.front() << "  ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    // reverse(q);
    int n = q.size();
    reverse(q, 2, 4);
    return 0;
}