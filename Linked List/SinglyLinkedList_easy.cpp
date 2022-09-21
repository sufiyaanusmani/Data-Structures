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

class SinglyLinkedList
{
private:
    Node *head;

public:
    // Constructor
    SinglyLinkedList()
    {
        head = NULL;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << endl;
        }
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
        }
    }

    void prepend(int data)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
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
            int count = 0;
            Node *temp = head;
            Node *prev = NULL;
            while (temp != NULL && count < index)
            {
                prev = temp;
                temp = temp->next;
                count++;
            }
            if (temp == NULL)
            {
                prev->next = n;
            }
            else
            {
                n->next = temp;
                prev->next = n;
            }
        }
    }

    void deleteFirstNode()
    {
        if (head != NULL)
        {
            if (head->next == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {
                Node *toDelete = head;
                head = head->next;
                delete toDelete;
            }
        }
    }

    void deleteLastNode()
    {
        if (head != NULL)
        {
            if (head->next == NULL)
            {
                delete head;
                head = NULL;
            }
            else
            {
                Node *temp = head;
                Node *prev = NULL;
                while (temp->next != NULL)
                {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = NULL;
                delete temp;
            }
        }
    }

    void deleteNode(int index)
    {
        if (head != NULL)
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
                while (temp != NULL && count < index)
                {
                    prev = temp;
                    temp = temp->next;
                    count++;
                }
                if (temp != NULL)
                {
                    prev->next = temp->next;
                    delete temp;
                }
            }
        }
    }

    bool isInList(int data)
    {
        if (head == NULL)
        {
            return false;
        }
        else
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
    SinglyLinkedList sll;

    // append
    sll.append(10);
    sll.append(20);
    sll.append(30);

    // print
    sll.print();

    // prepend
    sll.prepend(40);
    sll.prepend(50);
    sll.prepend(60);
    sll.print();

    // insert
    sll.insert(3, 45);
    sll.print();

    // delete first node
    sll.deleteFirstNode();
    sll.print();

    // delete last node
    sll.deleteLastNode();
    sll.print();

    // delete node
    sll.deleteNode(3);
    sll.print();

    // searching
    cout << sll.isInList(77) << endl;
    cout << sll.isInList(40) << endl;

    return 0;
}