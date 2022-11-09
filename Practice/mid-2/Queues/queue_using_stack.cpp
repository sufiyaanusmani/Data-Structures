// Sufiyaan Usmani

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> st, temp;
    int size;

public:
    void enqueue(int data)
    {
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        st.push(data);
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        size++;
    }

    void dequeue()
    {
        if (st.empty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            st.pop();
        }
        size--;
    }

    void print()
    {
        if (st.empty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            int *arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = st.top();
                st.pop();
                cout << arr[i] << "  ";
            }
            for (int i = size - 1; i >= 0; i--)
            {
                st.push(arr[i]);
            }
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();
    q.dequeue();
    q.print();
    return 0;
}