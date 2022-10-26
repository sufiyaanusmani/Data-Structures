#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data = 0)
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
    SinglyLinkedList()
    {
        head = NULL;
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
            cout << "List: ";
            while (temp != NULL)
            {
                cout << temp->data << "   ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int count()
    {
        int count = 0;
        if (!isEmpty())
        {
            Node *temp = head;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
        }
        return count;
    }

    int sum()
    {
        int total = 0;
        if (!isEmpty())
        {
            Node *temp = head;
            while (temp != NULL)
            {
                total += temp->data;
                temp = temp->next;
            }
        }
        return total;
    }

    void pushFront(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAfter(Node *given, int data)
    {
        if (given == NULL)
        {
            cout << "Given node can not be empty" << endl;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = given->next;
            given->next = newNode;
        }
    }

    void pushBack(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = newNode;
        }
        else
        {
            Node *last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = newNode;
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
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteNode(int val)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            Node *prev = NULL;

            if (temp->data == val)
            {
                head = head->next;
                delete temp;
            }
            else
            {
                while (temp->data != val)
                {
                    prev = temp;
                    temp = temp->next;
                }
                if (temp == NULL)
                {
                    cout << "Value not found" << endl;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                }
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
            Node *temp = head;
            if (temp->next == NULL)
            {
                head = NULL;
                delete temp;
            }
            else
            {
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                Node *last = temp->next;
                temp->next = NULL;
                delete last;
            }
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
            Node *temp = head;
            Node *prev = NULL;

            while (temp != NULL)
            {
                prev = temp;
                temp = temp->next;
                delete prev;
            }
            head = NULL;
        }
    }

    SinglyLinkedList(const SinglyLinkedList &old)
    {
        head = NULL;
        Node *temp = old.head;
        Node *newNode;
        while (temp != NULL)
        {
            newNode = new Node(temp->data);
            if (head == NULL)
            {
                head = newNode;
            }
            temp = temp->next;
        }
    }

    void reverse()
    {
        Node *p, *q, *r;
        p = head;
        q = NULL;
        r = NULL;
        while (p != NULL)
        {
            head = p;
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
    }

    ~SinglyLinkedList()
    {
        deleteList();
    }
};

int main()
{
    SinglyLinkedList ll;
    ll.pushFront(4);
    ll.pushFront(3);
    ll.printList();
    ll.pushBack(99);
    ll.printList();
    ll.reverse();
    ll.printList();
    return 0;
}