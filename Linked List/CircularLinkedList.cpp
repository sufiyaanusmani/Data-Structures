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
                cout << temp->data << "   ";
                temp = temp->next;
            } while (temp != tail->next);
            cout << endl;
        }
    }

    void addToHead(int data)
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

    void addToTail(int data)
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

    void deleteFromHead()
    {
        if (tail == NULL)
        {
            cout << "List is already empty" << endl;
        }
        else
        {
            if (tail->next == tail)
            {
                // if only one node
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

    void deleteFromTail()
    {
        if (tail == NULL)
        {
            cout << "List is already empty" << endl;
        }
        else
        {
            if (tail->next == tail)
            {
                // if only one node
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

    void deleteNode(int data)
    {
        if (tail == NULL)
        {
            cout << "List is already empty" << endl;
        }
        else
        {
            if (tail->data == data && tail->next == tail)
            {
                delete tail;
                tail = NULL;
            }
            else
            {
                Node *temp = tail->next;
                Node *prev = tail;
                do
                {
                    if (temp->data == data)
                    {
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                } while (temp != tail->next);
                if (temp->data == data)
                {
                    prev->next = temp->next;
                    if (tail == temp)
                    {
                        tail = prev;
                    }
                    delete temp;
                }
                else
                {
                    cout << "Data not found" << endl;
                }
            }
        }
    }

    bool isInList(int data)
    {
        if (tail == NULL)
        {
            return false;
        }
        else
        {
            Node *temp = tail->next;
            do
            {
                if (temp->data == data)
                {
                    return true;
                }
                temp = temp->next;
            } while (temp != tail->next);
        }
        return false;
    }

    ~CircularLinkedList()
    {
        if (tail != NULL)
        {
            Node *temp = tail;
            Node *prev = NULL;
            while (temp != tail)
            {
                prev = temp;
                temp = temp->next;
                delete prev;
            }
        }
        delete tail;
        tail = NULL;
    }
};

int main()
{
    CircularLinkedList cll;
    cll.addToTail(30);
    cll.addToHead(5);
    cll.addToHead(10);
    cll.addToTail(20);
    cll.addToHead(15);
    cll.printList();
    cll.deleteFromHead();
    cll.printList();
    cll.addToHead(70);
    cll.addToTail(25);
    cll.addToHead(11);
    cll.printList();
    cll.deleteFromTail();
    cll.printList();
    cll.deleteNode(10);
    cll.printList();
    cll.deleteNode(1990);
    cll.printList();
    cll.deleteNode(70);
    cll.printList();
    cll.deleteNode(11);
    cll.printList();
    cll.deleteNode(5);
    cll.printList();
    cout << cll.isInList(90) << endl;
    cout << cll.isInList(20) << endl;
    return 0;
}