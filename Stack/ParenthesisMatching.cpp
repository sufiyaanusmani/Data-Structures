// Sufiyaan Usmani

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node()
    {
        next = NULL;
    }

    Node(char data)
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

    void push(char data)
    {
        Node *n = new Node(data);
        n->next = top;
        top = n;
    }

    void pop()
    {
        if (!isEmpty())
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isBalanced(string expression)
    {
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '(')
            {
                push(expression[i]);
            }
            else if (expression[i] == ')')
            {
                if (isEmpty())
                {
                    return false;
                }
                else
                {
                    pop();
                }
            }
        }
        if (isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack stack;
    cout << (stack.isBalanced("((a+b)*(c-d))") == true ? "Balanced" : "Not Balanced") << endl;
    return 0;
}