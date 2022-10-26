// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int *arr;
    int top;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    int pop()
    {
        int data = -1;
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            data = arr[top];
            top--;
        }
        return data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
            cout << endl;
        }
    }

    int getTop()
    {
        if (!isEmpty())
        {
            return arr[top];
        }
        return -1;
    }
};

int main()
{
    Stack stack(3);
    stack.display();
    cout << stack.getTop() << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    cout << stack.getTop() << endl;
    stack.push(40);
    stack.display();
    stack.pop();
    stack.pop();
    stack.display();
    return 0;
}