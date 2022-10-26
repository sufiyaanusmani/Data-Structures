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

    Node(int data, Node *n)
    {
        this->data = data;
        next = n;
    }
};

class CircularLinkedList
{
private:
    Node *tail;

public:
    CircularLinkedList()
    {
        tail = NULL;
    }

    void printList()
    {
        Node *p;

        if (tail == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            p = tail->next;
            do
            {
                cout << "  " << p->data;
                p = p->next;
            } while (p != tail->next);
            cout << endl;
        }
    }

    // insert at the front
    void pushFront(int data)
    {
        Node *newNode = new Node(data, NULL);
        if (tail == NULL)
        {
            tail = newNode;
            tail->next = newNode;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }
};

int main()
{

    return 0;
}