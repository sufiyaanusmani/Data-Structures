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
        prev = next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        prev = next = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = tail = NULL;
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "empty" << endl;
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

    void prepend(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void append(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
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
            while (temp != NULL && count != index)
            {
                prev = temp;
                temp = temp->next;
                count++;
            }
            if (temp != NULL)
            {
                n->next = temp;
                n->prev = prev;
                temp->prev = n;
                prev->next = n;
            }
            else
            {
                cout << "Invalid index" << endl;
            }
        }
    }

    void deleteFirstNode()
    {
        if (head == NULL)
        {
            cout << "empty" << endl;
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
                Node *temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
        }
    }

    void deleteLastNode()
    {
        if (head == NULL)
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
                Node *temp = tail;
                tail = tail->prev;
                tail->next = NULL;
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
                cout << "index 0" << endl;
                deleteFirstNode();
            }
            else
            {
                Node *temp = head;
                Node *prev = NULL;
                int count = 0;
                while (temp != NULL && count != index)
                {
                    prev = temp;
                    temp = temp->next;
                    count++;
                }
                if (temp != NULL)
                {
                    if (temp->next == NULL)
                    {
                        cout << "last node" << endl;
                        deleteLastNode();
                    }
                    else
                    {
                        cout << "between" << endl;
                        prev->next = temp->next;
                        temp->next->prev = prev;
                        delete temp;
                    }
                }
                else
                {
                    cout << "Invalid index" << endl;
                }
            }
        }
    }

    void reverse()
    {
        if (head != NULL)
        {
            Node *p = head;
            Node *q = NULL;
            Node *r = NULL;
            tail = head;
            while (p != NULL)
            {
                r = q;
                q = p;
                p = p->next;
                q->next = r;
                q->prev = p;
            }
            head = q;
        }
    }

    void update(int index, int data)
    {
        if (head != NULL)
        {
            Node *temp = head;
            int count = 0;
            while (temp != NULL && count < index)
            {
                temp = temp->next;
                count++;
            }
            temp->data = data;
        }
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.prepend(10);
    dll.append(20);
    dll.append(30);
    dll.prepend(15);
    dll.printList();
    dll.insert(2, 40);
    dll.printList();
    dll.deleteFirstNode();
    dll.deleteLastNode();
    dll.printList();
    dll.append(90);
    dll.append(78);
    dll.append(40);
    dll.append(110);
    dll.printList();
    dll.printList();
    dll.reverse();
    dll.printList();
    dll.update(2, 30);
    dll.printList();
    dll.insert(6, 25);
    dll.printList();
    dll.deleteNode(7);
    dll.printList();
    return 0;
}