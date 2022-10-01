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

    Node(int data)
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

    void printList()
    {
        if (tail != NULL)
        {
            Node *temp = tail->next;
            do
            {
                cout << temp->data << "  ";
                temp = temp->next;
            } while (temp != tail->next);
        }
        cout << endl;
    }

    void append(int data)
    {
        Node *n = new Node(data);
        if (tail == NULL)
        {
            tail = n;
            tail->next = n;
        }
        else
        {
            n->next = tail->next;
            tail->next = n;
            tail = n;
        }
    }

    void prepend(int data)
    {
        Node *n = new Node(data);
        if (tail == NULL)
        {
            tail = n;
            tail->next = n;
        }
        else
        {
            n->next = tail->next;
            tail->next = n;
        }
    }

    void deleteFirstNode()
    {
        if (tail != NULL)
        {
            if (tail->next == NULL)
            {
                delete tail;
                tail = NULL;
            }
            else
            {
                Node *toDelete = tail->next;
                tail->next = toDelete->next;
                delete toDelete;
            }
        }
    }

    void deleteLastNode()
    {
        if (tail != NULL)
        {
            if (tail->next == NULL)
            {
                delete tail;
                tail = NULL;
            }
            else
            {
                Node *temp = tail->next;
                while (temp->next != tail)
                {
                    temp = temp->next;
                }
                temp->next = tail->next;
                delete tail;
                tail = temp;
            }
        }
    }
};

int main()
{
    CircularLinkedList cll;

    // append
    cll.append(10);
    cll.append(20);
    cll.append(30);

    // print
    cll.printList();

    // prepend
    cll.prepend(40);
    cll.prepend(50);
    cll.printList();

    // delete first node
    cll.deleteFirstNode();
    cll.printList();

    // delete last node
    cll.deleteLastNode();
    cll.printList();
    return 0;
}