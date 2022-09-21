// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    // Constructor
    SinglyLinkedList()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "   ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{

    return 0;
}