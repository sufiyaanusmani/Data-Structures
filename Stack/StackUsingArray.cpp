// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *arr;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[this->size];
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
            cout << "Error: stack is full" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    int pop()
    {
        int x = -1;
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            x = arr[top];
            top--;
        }
        return x;
    }

    bool isSafe(int index)
    {
        if (index >= 0 && index <= top)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int peek(int index)
    {
        int x = -1;
        if (isSafe(index))
        {
            x = arr[top - index + 1];
        }
        else
        {
            cout << "Error: Invalid Index" << endl;
        }
        return x;
    }

    int stackTop()
    {
        return arr[top];
    }

    void print()
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
        }
        cout << endl;
    }

    ~Stack()
    {
        if (arr != NULL)
        {
            delete[] arr;
        }
        arr = NULL;
    }
};

int main()
{
    Stack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.print();
    cout << "Popped: " << stack.pop() << endl;
    stack.print();
    stack.push(4);
    stack.push(5);
    stack.print();
    stack.push(6);
    stack.push(7);
    stack.print();
    cout << "Top: " << stack.stackTop() << endl;
    cout << "Peek: " << stack.peek(2) << endl;
    return 0;
}