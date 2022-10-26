#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int data = 0)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
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
                cout << temp->data << "  " << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void pushBack(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insertAfter(Node *given, int data)
    {
        if (given == NULL)
        {
            cout << "Can not be null" << endl;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = given->next;
            given->next = newNode;

            newNode->prev = given;
            newNode->next->prev = newNode;

            if (given == tail)
            {
                tail = newNode;
            }

            size++;
        }
    }

    void insertBefore(Node *given, int data)
    {
        if (given == NULL)
        {
            cout << "Can not be NULL" << endl;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = given;
            newNode->prev = given->prev;

            given->prev->next = newNode;
            given->prev = newNode;

            size++;
        }
    }

    void deleteList()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *t1, *t2;
            t1 = NULL;
            t2 = head;
            while (t2 != NULL)
            {
                t1 = t2;
                t2 = t2->next;
                delete t1;
            }
            size = 0;
        }
    }

    ~DoublyLinkedList()
    {
        deleteList();
    }
};

int main()
{

    return 0;
}