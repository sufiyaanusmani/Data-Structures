// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 4

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node()
    {
        data = 0;
        next = previous = NULL;
    }

    Node(int data)
    {
        this->data = data;
        previous = next = NULL;
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
        head = NULL;
    }

    void concatenate(DoublyLinkedList &m)
    {
        // this algorithms is efficient since its time complexity is constant: O(1)
        if (head == NULL || m.head == NULL)
        {
            cout << "Error: One or both lists are empty" << endl;
        }
        else
        {
            tail->next = m.head;
            m.head->previous = tail;
            tail = m.tail;
        }
    }

    void printList()
    {
        if (head == NULL)
        {
            // checking if list is empty
            cout << "List is empty" << endl;
            Sleep(1000);
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
            // checking if list is empty
            head = tail = n;
        }
        else
        {
            tail->next = n;
            n->previous = tail;
            tail = n;
        }
    }

    void prepend(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            // checking if list is empty
            head = tail = n;
        }
        else
        {
            n->next = head;
            head->previous = n;
            head = n;
        }
    }

    void insertAtIndex(int index, int data)
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
            while (temp != NULL && count != index)
            {
                prev = temp;
                temp = temp->next;
                count++;
            }
            if (temp != NULL)
            {
                n->next = temp;
                n->previous = prev;

                prev->next = n;
                temp->previous = n;
            }
            else
            {
                cout << "Error: Invalid Index" << endl;
                Sleep(1000);
            }
        }
    }
};

int main()
{
    // Doubly Linked List L
    DoublyLinkedList l;
    l.append(10);
    l.append(30);
    l.prepend(5);
    l.append(80);

    cout << "Linked List L: ";
    l.printList();

    // Doubly Linked List m
    DoublyLinkedList m;
    m.append(4);
    m.prepend(90);
    m.append(50);
    m.append(35);
    m.insertAtIndex(1, 35);

    cout << "\nLinked List M: ";
    m.printList();

    // Concatenating both lists
    l.concatenate(m);
    cout << "\nConcatenated List: ";
    l.printList();
    return 0;
}