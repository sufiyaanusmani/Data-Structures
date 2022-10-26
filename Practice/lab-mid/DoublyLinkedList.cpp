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

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
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
            while (temp != NULL)
            {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << " NULL" << endl;
        }
    }

    void append(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void prepend(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void insertAfter(int index, int data)
    {
        Node *n = new Node(data);
        int count = 0;
        Node *temp = head;
        while (temp != NULL && count != index)
        {
            temp = temp->next;
            count++;
        }
        if (temp != NULL)
        {
            if (temp == tail)
            {
                append(data);
            }
            else
            {
                n->next = temp->next;
                temp->next->prev = n;
                temp->next = n;
                n->prev = temp;
            }
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }

    void deleteFirstNode()
    {
        if (head == NULL)
        {
            cout << "Empty" << endl;
        }
        else
        {
            if (head->next == NULL)
            {
                delete head;
                head = tail = NULL;
            }
            else
            {
                Node *temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
        }
    }

    void deleteLastNode()
    {
        if (head == NULL)
        {
            cout << "Empty" << endl;
        }
        else
        {
            if (head->next == NULL)
            {
                delete head;
                head = tail = NULL;
            }
            else
            {
                Node *temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
        }
    }

    void deleteNode(int index)
    {
        if (head == NULL)
        {
            cout << "Empty" << endl;
        }
        else
        {
            if (index == 0)
            {
                deleteFirstNode();
            }
            else
            {
                Node *temp = head;
                Node *prev = NULL;
                int count = 0;
                while (temp != NULL && count != index)
                {
                    prev = temp;
                    temp = temp->next;
                    count++;
                }
                if (temp != NULL)
                {
                    if (temp == tail)
                    {
                        deleteLastNode();
                    }
                    else
                    {
                        prev->next = temp->next;
                        temp->next->prev = prev;
                        delete temp;
                    }
                }
                else
                {
                    cout << "Invalid index" << endl;
                }
            }
        }
    }

    void reverse()
    {
        if (head != NULL)
        {
            Node *p = head;
            Node *q = NULL;
            Node *r = NULL;
            tail = head;
            while (p != NULL)
            {
                r = q;
                q = p;
                p = p->next;
                q->next = r;
                q->prev = p;
            }
            head = q;
        }
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.prepend(10);
    dll.print();
    dll.insertAfter(0, 2);
    dll.print();
    dll.insertAfter(0, 1);
    dll.append(20);
    dll.append(50);
    dll.print();
    dll.print();
    dll.deleteNode(1);
    dll.print();
    dll.reverse();
    dll.print();
    return 0;
}