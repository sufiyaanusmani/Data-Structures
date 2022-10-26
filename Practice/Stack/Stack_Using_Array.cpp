#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr; // to store data
    int top;  // to point on top most element
    int size; // total size of stack

public:
    Stack()
    {
        size = 10;
        top = -1;
        arr = new int[size];
    }

    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[this->size];
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == size - 1);
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        else
        {
            int data = arr[top];
            top--;
            return data;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        else
        {
            return arr[top];
        }
    }

    int getTop()
    {
        return top;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    Stack s;
    cout << "Top: " << s.getTop() << endl;
    cout << "Add 10, 20, and 30 to the Stack." << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Peek: " << s.peek() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "isEmpty: " << s.isEmpty() << endl;
    cout << "Top: " << s.getTop() << endl;
    s.display();
    return 0;
}