#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

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
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    char peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return '*';
        }
        else
        {
            return top->data;
        }
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return '*';
        }
        else
        {
            Node *temp = top;
            char value = temp->data;
            top = top->next;
            delete temp;
            return value;
        }
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

bool isBalanced(string str)
{
    Stack stack;
    char ch;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stack.push(str[i]);
        }
        else
        {
            if (stack.isEmpty())
            {
                return false;
            }
            else
            {
                if (str[i] == ')' || str[i] == '}' || str[i] == ']')
                {
                    if (stack.isEmpty())
                    {
                        return false;
                    }
                    else
                    {
                        switch (str[i])
                        {
                        case ')':
                            ch = stack.pop();
                            if (ch == '(')
                            {
                                break;
                            }
                            else
                            {
                                return false;
                            }
                        case '}':
                            ch = stack.pop();
                            if (ch == '{')
                            {
                                break;
                            }
                            else
                            {
                                return false;
                            }
                        case ']':
                            ch = stack.pop();
                            if (ch == '[')
                            {
                                break;
                            }
                            else
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }

    if (stack.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Stack s;
    string str = "{()}[{}([])]";

    // Function call
    if (isBalanced(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}