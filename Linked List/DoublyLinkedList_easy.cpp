// Sufiyaan Usmani

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
        prev = NULL;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        prev = next = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void print()
    {
        if (head != NULL)
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "   ";
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void append(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
        }
    }

    void prepend(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            head->prev = n;
            n->next = head;
            head = n;
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
            Node *previous = NULL;
            int count = 0;
            while (temp != NULL && count < index)
            {
                previous = temp;
                temp = temp->next;
                count++;
            }
            if (temp == NULL)
            {
                append(data);
            }
            else
            {
                previous->next = n;
                n->next = temp;
                n->prev = previous;
                temp->prev = n;
            }
        }
    }

    int deleteFirstNode()
    {
        int val = head->data;
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *toDelete = head;
            head = head->next;
            head->prev = NULL;
            delete toDelete;
        }
        return val;
    }

    int deleteLastNode()
    {
        if (head != NULL)
        {
            int val;
            if (head->next == NULL)
            {
                val = head->data;
                delete head;
                head = NULL;
            }
            else
            {
                Node *temp = head;
                Node *previous = NULL;
                while (temp->next != NULL)
                {
                    previous = temp;
                    temp = temp->next;
                }
                val = temp->data;
                previous->next = NULL;
                delete temp;
            }
            return val;
        }
    }

    int deleteNode(int index)
    {
        if (head != NULL)
        {
            int val;
            if (index == 0)
            {
                val = deleteFirstNode();
            }
            else
            {
                Node *temp = head;
                Node *previous = NULL;
                int count = 0;
                while (temp != NULL && count < index)
                {
                    previous = temp;
                    temp = temp->next;
                    count++;
                }
                if (temp == NULL)
                {
                    cout << "Data not found" << endl;
                }
                else
                {
                    val = temp->data;
                    previous->next = temp->next;
                    temp->next->prev = previous;
                    delete temp;
                }
            }
            return val;
        }
    }

    bool isInList(int data)
    {
        if (head != NULL)
        {
            Node *temp = head;
            while (temp != NULL && temp->data != data)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
};

int main()
{
    DoublyLinkedList dll;

    // prepend
    dll.prepend(10);
    dll.prepend(20);
    dll.prepend(30);

    // print
    dll.print();

    // append
    dll.append(40);
    dll.append(50);

    // print
    dll.print();

    // insert
    dll.insert(3, 65);
    dll.insert(30, 75);

    dll.print();

    // adding more elements
    dll.insert(6, 95);
    dll.append(23);
    dll.prepend(15);

    dll.print();

    // deleting first node
    cout << dll.deleteFirstNode() << endl;
    dll.print();

    // deleting last node
    cout << dll.deleteLastNode() << endl;
    dll.print();

    // deleting node;
    cout << dll.deleteNode(4) << endl;
    dll.print();
    cout << dll.deleteNode(0) << endl;
    dll.print();

    // searching
    cout << dll.isInList(75) << endl;
    cout << dll.isInList(23) << endl;
    return 0;
}