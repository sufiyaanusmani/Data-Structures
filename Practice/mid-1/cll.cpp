#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
    {
        next = NULL;
    }
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class CircularLinkedList
{
public:
    node *tail;

    CircularLinkedList()
    {
        tail = NULL;
    }
    void print()
    {
        if (tail == NULL)
        {
            cout << "   Link List Is Empty ";
        }
        else
        {
            node *temp = tail->next; // here tail->next === head
            cout << "(<->";
            do
            {
                cout << temp->data << "<->";
                temp = temp->next;
            } while (temp != tail->next);
            cout << ")";
        }
    }
    void prependatstart(int data)
    {
        node *n = new node(data);
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
    void appendatEnd(int data)
    {
        node *n = new node(data);
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
    void insert(int index, int data)
    {
        node *n = new node(data);
        if (index == 0)
        {
            prependatstart(data);
        }
        else
        {
            node *temp = tail->next;
            node *prev = NULL;
            int count = 0;
            do
            {
                prev = temp;
                temp = temp->next;
                count++;
            } while (temp != tail->next && count < index);

            if (count == index)
            {
                if (temp == tail && count == index)
                {
                    appendatEnd(data);
                }
                else
                {
                    n->next = temp;
                    prev->next = n;
                }
            }
            else
            {
                cout << "Invalid Index";
            }
        }
    }
    void deleteFirstNode()
    {
        if (tail == NULL)
        {
            cout << " list is empty ";
        }
        else
        {
            if (tail->next == tail)
            {
                delete tail;
                tail = NULL;
            }
            else
            {
                node *temp = tail->next;
                tail->next = temp->next;
                delete temp;
            }
        }
    }

    void deletelastnode()
    {
        if (tail == NULL)
        {
            cout << "List does not exist";
        }
        else
        {
            if (tail->next == tail)
            {
                delete tail;
                tail = NULL;
            }
            else
            {
                node *temp = tail->next;
                node *prev = NULL;
                do
                {
                    prev = temp;
                    temp = temp->next;
                } while (temp != tail);
                prev->next = tail->next;
                tail = prev;
                delete temp;
            }
        }
    }

    void deletenode(int index)
    {
        if (tail == NULL)
        {
        }
        else
        {
            if (index == 0)
            {
                deleteFirstNode();
            }
            else
            {
                node *temp = tail->next;
                node *prev = NULL;
                int count = 0;
                do
                {
                    prev = temp;
                    temp = temp->next;
                    count++;
                } while (temp != tail->next && count < index);
                if (index == count && temp == tail)
                {
                    deletelastnode();
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                }
            }
        }
    }
};
int main()
{
    CircularLinkedList c;
    c.prependatstart(8);
    c.appendatEnd(76);
    c.prependatstart(65);
    c.insert(2, 735);
    // c.deleteFirstNode();
    // c.deletelastnode();
    // c.deletenode(1);
    c.print();
    c.deletenode(4);
    c.print();
}