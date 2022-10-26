// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        next = prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};

class CDLL
{
private:
    Node *head;
    Node *tail;
    int count;

public:
    CDLL()
    {
        head = tail = NULL;
        count = 0;
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
            for (int i = 0; i < count; i++)
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
            head->next = head->prev = tail->next = tail->prev = NULL;
        }
        else
        {
            n->next = head;
            head->prev = n;
            head = n;
            head->prev = tail;
            tail->next = head;
        }
        count++;
    }

    void append(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = tail = NULL;
            head->next = head->prev = tail->next = tail->prev = NULL;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
            n->next = head;
            head->prev = tail;
        }
        count++;
    }

    void insert(int index, int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            if (index == 0)
            {
                prepend(data);
                count++;
            }
            else
            {
                cout << "Index out of range" << endl;
            }
        }
        else
        {
            if (index > count)
            {
                cout << "Index out of range" << endl;
            }
            else if (index == count)
            {
                append(data);
                count++;
            }
            else
            {
                Node *temp = head;
                Node *prev = NULL;
                for (int i = 1; i < count; i++)
                {
                    prev = temp;
                    temp = temp->next;
                    if (i == index)
                    {
                        n->next = temp;
                        n->prev = prev;
                        temp->prev = n;
                        prev->next = n;
                        count++;
                        break;
                    }
                }
            }
        }
    }

    void deleteHead()
    {
        if (head == NULL)
        {
            cout << "Empty" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = temp->prev;
            tail->next = head;
            delete temp;
            count--;
        }
    }

    void deleteTail()
    {
        if (head == NULL)
        {
            cout << "Empty" << endl;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
            count--;
        }
    }

    void search(int data)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            bool flag = false;
            for (int i = 0; i < count; i++)
            {
                if (temp->data == data)
                {
                    cout << "Found" << endl;
                    flag = true;
                    break;
                }
                temp = temp->next;
            }
            if (flag == false)
            {
                cout << "Not found" << endl;
            }
        }
    }

    void update(int index, int data)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            if (index >= count)
            {
                cout << "Invalid index" << endl;
            }
            else
            {
                Node *temp = head;
                for (int i = 0; i < count; i++)
                {
                    if (i == index)
                    {
                        temp->data = data;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
    }
};

int main()
{
    CDLL l;
    l.prepend(10);
    l.prepend(20);
    l.prepend(30);
    l.print();
    l.append(40);
    l.append(50);
    l.print();
    l.insert(1, 90);
    l.print();
    l.deleteHead();
    l.print();
    l.deleteTail();
    l.print();
    l.search(30);
    l.update(0, 45);
    l.print();
    return 0;
}