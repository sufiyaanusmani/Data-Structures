// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 3

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        data = 0;
        prev = next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        prev = next = NULL;
    }
};

class CircularDoubleLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    CircularDoubleLinkedList()
    {
        head = tail = NULL;
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            do
            {
                cout << temp->data << "  ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
    }

    void prepend(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            // if list is empty
            head = tail = n;
        }
        else
        {
            n->next = head;
            n->prev = tail;

            head->prev = n;
            tail->next = n;

            head = n;
        }
    }

    void append(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            // if list is empty
            head = tail = n;
        }
        else
        {
            n->next = head;
            n->prev = tail;

            tail->next = n;
            head->prev = n;

            tail = n;
        }
    }

    void insert(int index, int data)
    {
        Node *n = new Node(data);
        if (index == 0)
        {
            prepend(data);
        }
        else
        {
            Node *temp = head;
            Node *prev = NULL;
            int count = 0;
            do
            {
                prev = temp;
                temp = temp->next;
                count++;
            } while (temp != head && count != index);
            if (temp != head)
            {
                if (temp == tail)
                {
                    append(data);
                }
                else
                {
                    n->next = temp;
                    n->prev = prev;
                    prev->next = n;
                    temp->prev = n;
                }
            }
            else
            {
                cout << "Error: Invalid Index" << endl;
            }
        }
    }

    void deleteFirstNode()
    {
        if (head == NULL)
        {
            // if list is empty
            cout << "List is already empty" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
    }

    void deleteLastNode()
    {
        if (head == NULL)
        {
            cout << "List is already empty" << endl;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }

    void deleteNode(int index)
    {
        if (head == NULL)
        {
            cout << "List is already empty" << endl;
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
                do
                {
                    prev = temp;
                    temp = temp->next;
                    count++;
                } while (temp != head && count != index);
                if (temp != head)
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
                    cout << "Error: Invalid Index" << endl;
                }
            }
        }
    }
};

int main()
{
    CircularDoubleLinkedList ll;
    ll.append(10);
    ll.append(20);
    ll.append(30);
    ll.printList();
    ll.prepend(40);
    ll.prepend(50);
    ll.printList();
    ll.insert(4, 99);
    ll.printList();
    ll.deleteNode(6);
    ll.printList();
    return 0;
}