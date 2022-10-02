// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
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

    void print()
    {
        if (top == NULL)
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

    void push(int data)
    {
        Node *n = new Node(data);
        if (n == NULL)
        {
            // if heap is full
            cout << "Heap is full" << endl;
        }
        else
        {
            n->next = top;
            top = n;
        }
    }

    int pop()
    {
        int x = -1;
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            x = temp->data;
            delete temp;
        }
        return x;
    }
};

int main()
{
    Stack stack;
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.print();
    cout << "Pop: " << stack.pop() << endl;
    stack.print();
    cout << "Pop: " << stack.pop() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Pop: " << stack.pop() << endl;
    stack.print();
    return 0;
}