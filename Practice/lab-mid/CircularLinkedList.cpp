// Sufiyaan Usmani

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

    void print()
    {
        if (tail == NULL)
        {
            cout << "Empty" << endl;
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

    void insertAfter(int index, int data)
    {
        Node *n = new Node(data);
        if (tail == NULL)
        {
            cout << "Empty" << endl;
        }
        else if (index == 0)
        {
            Node *temp = tail->next;
            n->next = temp->next;
            temp->next = n;
        }
        else
        {
            Node *temp = tail->next;
            int count = 0;
            do
            {
                temp = temp->next;
                count++;
            } while (temp != tail->next && count != index);
            if (temp != tail->next)
            {
                if (temp == tail)
                {
                    append(data);
                }
                else
                {
                    n->next = temp->next;
                    temp->next = n;
                }
            }
            else
            {
                cout << "Invalid index" << endl;
            }
        }
    }

    void deleteFirstNode()
    {
        if (tail == NULL)
        {
            cout << "Empty" << endl;
        }
        else
        {
            Node *temp = tail->next;
            tail->next = temp->next;
            delete temp;
        }
    }

    void deleteLastNode()
    {
        if (tail == NULL)
        {
            cout << "Empty" << endl;
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

    void deleteNode(int index)
    {
        if (tail == NULL)
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
                Node *temp = tail->next;
                Node *prev = NULL;
                int count = 0;
                do
                {
                    prev = temp;
                    temp = temp->next;
                    count++;
                } while (temp != tail->next && count != index);
                if (temp != tail->next)
                {
                    if (temp == tail)
                    {
                        deleteLastNode();
                    }
                    else
                    {
                        prev->next = temp->next;
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
        if (tail != NULL)
        {
            Node *p = tail->next;
            Node *q = NULL;
            Node *r = NULL;
            Node *temp = tail->next;
            do
            {
                r = q;
                q = p;
                p = p->next;
                q->next = r;
            } while (p != temp);
            tail = temp;
            tail->next = q;
        }
    }
};

int main()
{
    CircularLinkedList cll;
    cll.append(10);
    cll.append(20);
    cll.print();
    cll.prepend(30);
    cll.print();
    cll.insertAfter(0, 40);
    cll.print();
    cll.insertAfter(2, 70);
    cll.print();
    cll.insertAfter(5, 80);
    cll.print();
    cll.deleteNode(5);
    cll.print();
    cll.reverse();
    cll.print();
    return 0;
}