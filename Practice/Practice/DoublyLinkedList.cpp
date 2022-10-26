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
            cout << temp->data << "   ";
            temp = temp->next;
        }
        cout << endl;
    }

    void pushBack(int val)
    {
        Node *newNode = new Node(val);
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
    }

    void insertAfter(Node *given, int val)
    {
        if (given == NULL)
        {
            cout << "Given node can not be NULL" << endl;
        }
        else
        {
            Node *newNode = new Node(val);
            newNode->next = given->next;
            given->next = newNode;

            newNode->prev = given;
            newNode->next->prev = newNode;

            if (given == tail)
            {
                tail = newNode;
            }
        }
    }
};

int main()
{

    return 0;
}