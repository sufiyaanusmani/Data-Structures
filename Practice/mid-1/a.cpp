#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkList()
    {
        head = NULL;
        tail = NULL;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << " Link list does not exist ";
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "<->";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    void appendatEnd(int data)
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

    void Prependatstart(int data)
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

    void insert(int index, int data)
    {
        Node *n = new Node(data);
        if (index == 0)
        {
            Prependatstart(data);
        }
        else
        {
            Node *temp = head;
            Node *prev = NULL;
            int count = 0;
            while (temp != NULL && count < index)
            {
                count++;
                prev = temp;
                temp = temp->next;
            }
            if (temp != NULL)
            {
                if (temp->next == NULL)
                {
                    appendatEnd(data);
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
                cout << "Invalid Index";
            }
        }
    }

    int search(int data)
    {
        if (head == NULL)
        {
            cout << "No link list to search data";
            return false;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                return data;
            }
            temp = temp->next;
        }
        return false;
    }
    void update(int index, int data)
    {
        if (index == 0)
        {
            head->data = data;
        }
        Node *temp = head;
        int count = 0;
        while (count < index && temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        temp->data = data;
    }

    void deleteatstart()
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
                Node *Todelete = head;
                head = head->next;
                delete Todelete;
            }
        }
    }
    void deleteatEnd()
    {
        if (head != NULL)
        {
            if (head->next == NULL)
            {
                delete head;
                head = NULL;
            }
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
        if (index == 0)
        {
            deleteatstart();
        }
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
            deleteatEnd();
        }
        prev->next = temp->next;
        delete temp;
    }
};
int main()
{
    DoublyLinkList d;
    d.Prependatstart(89);
    d.Prependatstart(76);
    d.appendatEnd(88);
    d.appendatEnd(432);
    d.insert(0, 763);
    d.insert(4, 998);
    d.print();
    d.deleteNode(50);
    d.print();
}