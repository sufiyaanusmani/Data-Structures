// Sufiyaan Usmani

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
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
                cout << temp->data << "   ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void addToHead(int data)
    {
        Node *newNode = new Node(data, head);
        head = newNode;
        if (tail == NULL)
        {
            tail = head;
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
            tail = tail->next;
        }
    }

    int deleteFromHead()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return -1;
        }
        else
        {
            Node *temp = head;
            int val = head->data;
            // if only one node
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
    }

    int deleteFromTail()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return -1;
        }
        else
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
                tail->next = NULL;
            }
            return val;
        }
    }

    void deleteNode(int data)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            if (head == tail && head->data == data)
            {
                getch();
                delete head;
                head = tail = NULL;
            }
            else if (head->data == data)
            {
                getch();
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                Node *temp = head;
                Node *prev = NULL;
                while (temp != NULL && temp->data != data)
                {
                    prev = temp;
                    temp = temp->next;
                }
                if (temp != NULL)
                {
                    prev->next = temp->next;
                    if (temp == tail)
                    {
                        tail = prev;
                    }
                    delete temp;
                }
                else
                {
                    cout << "Data not found" << endl;
                    Sleep(2000);
                }
            }
        }
    }

    bool isInList(int data)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return false;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL && temp->data != data)
            {
                temp = temp->next;
            }
            if (temp != NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    ~SinglyLinkedList()
    {
        if (!isEmpty())
        {
            Node *temp = head;
            while (temp != NULL)
            {
                head = temp;
                temp = temp->next;
                delete head;
            }
        }
        head = NULL;
    }
};

int main()
{
    SinglyLinkedList ll;
    int choice, data;
    while (1)
    {
        system("cls");
        cout << "1. View List" << endl;
        cout << "2. Insert at front" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Delete head node" << endl;
        cout << "5. Delete tail node" << endl;
        cout << "6. Delete node" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case 1:
            ll.printList();
            cout << "Press any key to continue...";
            getch();
            break;
        case 2:
            cout << "Enter data to insert: ";
            cin >> data;
            ll.addToHead(data);
            break;
        case 3:
            cout << "Enter data to insert: ";
            cin >> data;
            ll.addToTail(data);
            break;
        case 4:
            ll.deleteFromHead();
            break;
        case 5:
            ll.deleteFromTail();
            break;
        case 6:
            cout << "Enter data to delete: ";
            cin >> data;
            ll.deleteNode(data);
            break;
        default:
            cout << "Wrong choice entered, please enter a valid choice" << endl;
            Sleep(2000);
            break;
        }
    }
    return 0;
}