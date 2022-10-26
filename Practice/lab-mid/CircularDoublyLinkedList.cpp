// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data = 0)
    {
        this->data = data;
        prev = next = NULL;
    }
};

class CircularDoublyLinkedList
{
private:
    Node *head, *tail;

public:
    CircularDoublyLinkedList()
    {
        head = tail = NULL;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "Empty" << endl;
        }
        else
        {
            Node *temp = head;
            do
            {
                cout << temp->data << "  ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
    }

    void prepend(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = tail = n;
            n->next = n;
            n->prev = n;
        }
        else
        {
            n->next = head;
            head->prev = n;
            tail->next = n;
            n->prev = tail;
            head = n;
        }
    }

    void append(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = tail = NULL;
            n->next = n;
            n->prev = n;
        }
        else
        {
            n->next = head;
            head->prev = n;
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void insertAfter(int index, int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            cout << "Empty" << endl;
        }
        else
        {
            Node *temp = head;
            int count = 0;
            do
            {
                temp = temp->next;
                count++;
            } while (temp != head && count != index);
            if (temp != head || index == 0)
            {
                n->next = temp->next;
                temp->next->prev = n;
                temp->next = n;
                n->prev = temp;
            }
            else
            {
                cout << "Invalid index" << endl;
            }
        }
    }
};

int main()
{
    CircularDoublyLinkedList ll;
    ll.prepend(10);
    ll.prepend(20);
    ll.print();
    ll.append(30);
    ll.print();
    ll.insertAfter(0, 90);
    ll.print();
    ll.insertAfter(4, 80);
    ll.print();
    return 0;
}