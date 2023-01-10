// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 1

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
            cout << "Stack Overflow" << endl;
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

    int peek()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            x = arr[top];
        }
        return x;
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

int main(){
    Stack stack(10);
    // part 1
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    stack.push(100);
    stack.print();

    // part 2
    cout << "Inserting 110 to full stack" << endl;
    stack.push(110);

    // part 3
    cout << endl;

    while(!stack.isEmpty()){
        cout << "Popping: " << stack.peek() << endl;
        stack.pop();
    }
    cout << "\nTrying to pop from empty stack" << endl;
    stack.pop();
    return 0;
}