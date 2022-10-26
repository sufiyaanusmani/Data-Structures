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

    Node(int data, Node *n = NULL)
    {
        this->data = data;
        next = n;
    }
};

class SinglyLinkedList
{
private:
    Node *head, *tail;

public:
    SinglyLinkedList()
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

    void addToHead(int data)
    {
        Node *newNode = new Node(data, head);
        head = newNode;
        if (tail == NULL)
        {
            tail = newNode;
        }
    }

    void addToTail(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int deleteFromHead()
    {
        Node *temp = head;
        int val = head->data;
        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        return val;
    }

    int deleteFromTail()
    {
        int val = tail->data;
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            temp->next = NULL;
        }
        return val;
    }

    void deleteNode(int val)
    {
        if (!isEmpty())
        {
            if (head == tail && head->data == val)
            {
                delete head;
                head = tail = NULL;
            }
            else
            {
                if (val == head->data)
                {
                    Node *temp = head;
                    head = head->next;
                    delete temp;
                }
                else
                {
                    Node *temp, *previous;
                    temp = head;
                    while (temp != NULL && temp->data != val)
                    {
                        previous = temp;
                        temp = temp->next;
                    }
                    if (temp != NULL)
                    {
                        previous->next = temp->next;
                        if (temp == tail)
                        {
                            tail = previous;
                        }
                        delete temp;
                    }
                }
            }
        }
    }

    bool isInList(int data)
    {
        Node *temp = head;
        bool found = false;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~SinglyLinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            head = temp;
            temp = temp->next;
            delete head;
        }
    }
};

int main()
{
    SinglyLinkedList ll;
    ll.addToHead(10);
    ll.addToHead(20);
    ll.addToTail(33);
    ll.addToTail(50);
    ll.addToHead(40);
    ll.printList();
    ll.deleteFromHead();
    ll.deleteFromTail();
    ll.deleteNode(33);
    ll.printList();
    return 0;
}