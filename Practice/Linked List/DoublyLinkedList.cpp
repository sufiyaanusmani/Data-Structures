// Sufiyaan Usmani

#include <iostream>
#include <windows.h>
using namespace std;

class Node
{
public:
    int data;
    Node *previous;
    Node *next;

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

class DoublyLinkedList
{
private:
    Node *head, *tail;

public:
    DoublyLinkedList()
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
        if (isEmpty())
        {
            Node *newNode = new Node(data);
            head = tail = newNode;
        }
        else
        {
            Node *newNode = new Node(data, head, NULL);
            head = newNode;
            head->next->previous = head;
        }
    }

    void addToTail(int data)
    {
        if (isEmpty())
        {
            Node *newNode = new Node(data);
            head = tail = newNode;
        }
        else
        {
            Node *newNode = new Node(data, NULL, tail);
            tail = newNode;
            tail->previous->next = tail;
        }
    }

    void deleteFromHead()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
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
            cout << "List is empty" << endl;
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
                tail->next = 0;
            }
        }
    }

    void deleteNode(int data)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            Sleep(1000);
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
                Node *prev = NULL;
                while (temp != NULL && temp->data != data)
                {
                    prev = temp;
                    temp = temp->next;
                }
                if (temp != NULL)
                {
                    prev->next = temp->next;
                    delete temp;
                    prev->next->previous = prev;
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
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    ~DoublyLinkedList()
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
        head = NULL;
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.addToHead(10);
    dll.addToHead(20);
    dll.addToTail(88);
    dll.addToHead(22);
    dll.addToHead(60);
    dll.addToTail(98);
    dll.printList();
    dll.deleteNode(10);
    dll.printList();

    return 0;
}