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

class CircularLinkedList
{
private:
    Node *tail;

public:
    CircularLinkedList()
    {
        tail = NULL;
    }

    bool isEmpty()
    {
        if (tail == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void printList()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = tail->next;
            cout << "List: ";

            do
            {
                cout << temp->data << "   ";
                temp = temp->next;
            } while (temp != tail->next);
            cout << endl;
        }
    }

    void pushFront(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            tail = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertAfter(Node *given, int val)
    {
        if (given == NULL)
        {
            cout << "Given node can not be null" << endl;
        }
        else
        {
            Node *newNode = new Node(val);
            newNode->next = given->next;
            given->next = newNode;
        }
    }

    void pushBack(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            tail = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
};

int main()
{
    CircularLinkedList ll;
    ll.pushBack(5);
    ll.pushFront(4);
    ll.printList();
    return 0;
}