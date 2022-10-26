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
        next = NULL;
    }
    Node(int data, Node *n = NULL)
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
        if (tail == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = tail->next;
            do
            {
                cout << temp->data << "  ";
                temp = temp->next;
            } while (temp != tail->next);
            cout << endl;
        }
    }

    void addToHead(int data)
    {
        Node *newNode = new Node(data);
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

    void addToTail(int data)
    {
        Node *newNode = new Node(data);
        if (tail == NULL)
        {
            tail = newNode;
            tail->next = newNode;
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
    ll.addToHead(10);
    ll.addToHead(20);
    ll.addToTail(30);
    ll.printList();

    return 0;
}