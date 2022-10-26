// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data = 0)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if (top == NULL)
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
        Node *n = new Node(data);
        n->next = top;
        top = n;
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
            Node *temp = top;
            top = top->next;
            data = temp->data;
            delete temp;
        }
        return data;
    }

    int peek()
    {
        int data = -1;
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            data = top->data;
        }
        return data;
    }

    int count()
    {
        int count = 0;
        Node *temp = top;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Node *temp = top;
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Stack stack;
    stack.display();
    stack.pop();
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Popped: " << stack.pop() << endl;
    cout << "Peek: " << stack.peek() << endl;
    stack.display();
    return 0;
}