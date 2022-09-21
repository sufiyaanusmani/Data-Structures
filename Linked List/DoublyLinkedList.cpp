// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *previous;
    Node *next;

public:
    Node()
    {
        previous = next = NULL;
    }

    Node(int data, Node *n = NULL, Node *p = NULL)
    {
        this->data = data;
        next = n;
        previous = p;
    }
};

class Node
{
private:
    Node *head, *tail;

public:
    Node()
    {
        head = tail = NULL;
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

    void printList()
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

    void addToHead(int data)
    {
        Node *n = new Node(data, head);
        if (isEmpty())
        {
            head = tail = n;
        }
        else
        {
            head = n;
            head->next->previous = head;
        }
    }

    void addToTail(int data)
    {
        if (isEmpty())
        {
            Node *n = new Node(data);
            head = tail = n;
        }
        else
        {
            Node *n = new Node(data, NULL, tail);
            tail = n;
            tail->previous->next = tail;
        }
    }

    void deleteFromHead()
    {
        if (isEmpty())
        {
            cout << "List is already empty" << endl;
        }
        else
        {
            if (head == tail)
            {
                delete head;
                head = tail = NULL;
            }
            else
            {
                head = head->next;
                delete head->previous;
                head->previous = NULL;
            }
        }
    }

    void deleteFromTail()
    {
        if (isEmpty())
        {
            cout << "List is already empty" << endl;
        }
        else
        {
            if (head == tail)
            {
                delete head;
                head = tail = NULL;
            }
            else
            {
                tail = tail->previous;
                delete tail->next;
                tail->next = NULL;
            }
        }
    }

    void deleteNode(int data)
    {
        if (isEmpty())
        {
            cout << "List is already empty" << endl;
        }
        else
        {
            if (head == tail && head->data == data)
            {
                delete head;
                head = tail = NULL;
            }
            else
            {
                Node *temp = head;
                while (temp != NULL && temp->data != data)
                {
                    temp = temp->next;
                }
                if (temp != NULL)
                {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
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
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return false;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp->data == data)
                {
                    return true;
                }
                temp = temp->next;
            }
        }
        return false;
    }

    ~Node()
    {
        if (!isEmpty())
        {
            Node *temp = head;
            while (temp != NULL)
            {
                head = temp;
                temp = temp->next;
                delete head;
            }
        }
        head = tail = NULL;
    }
};

int main()
{
    Node dll;
    dll.addToHead(10);
    dll.addToHead(20);
    dll.addToTail(30);
    dll.addToTail(40);
    dll.addToHead(70);
    dll.addToHead(90);
    dll.addToTail(80);
    dll.addToTail(66);
    dll.printList();
    dll.deleteFromHead();
    dll.printList();
    dll.deleteFromTail();
    dll.printList();
    dll.deleteNode(40);
    dll.printList();
    dll.deleteNode(35);
    dll.printList();
    cout << (dll.isInList(19) == true ? "True" : "False") << endl;
    cout << (dll.isInList(70) == true ? "True" : "False") << endl;
    return 0;
}