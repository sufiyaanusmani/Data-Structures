// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 3

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
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
            Sleep(500);
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
            cout << "\nPress any key to continue...";
            getch();
        }
    }

    void prepend(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            // if list is empty
            head = tail = n;
            n->prev = n->next = n;
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
            n->prev = n->next = n;
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

    void insertAtIndex(int index, int data)
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
                n->next = temp;
                n->prev = prev;
                prev->next = n;
                temp->prev = n;
            }
            else
            {
                cout << "Error: Invalid Index" << endl;
                Sleep(1000);
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
            if (head == tail)
            {
                // if only node present
                delete head;
                head = tail = NULL;
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
    }

    void deleteLastNode()
    {
        if (head == NULL)
        {
            cout << "List is already empty" << endl;
        }
        else
        {
            if (head == tail)
            {
                // if only node present
                delete head;
                head = tail = NULL;
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
    }

    void deleteAtIndex(int index)
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
                    Sleep(1000);
                }
            }
        }
    }

    void updateNodeAtIndex(int index, int data)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            if (index == 0)
            {
                head->data = data;
            }
            else
            {
                Node *temp = head;
                int count = 0;
                do
                {
                    temp = temp->next;
                    count++;
                } while (temp != head && count != index);
                if (temp != head)
                {
                    temp->data = data;
                }
                else
                {
                    cout << "Error: Invalid index" << endl;
                    Sleep(1000);
                }
            }
        }
    }

    // Destructor
    ~CircularDoubleLinkedList()
    {
        if (head != NULL)
        {
            Node *temp = head;
            while (temp != tail)
            {
                head = temp;
                temp = temp->next;
                delete head;
            }
            delete tail;
        }
        head = tail = NULL;
    }
};

int main()
{
    CircularDoubleLinkedList ll;
    int choice, index, data;
    while (1)
    {
        system("cls");
        cout << "1. Insert at the end (append)" << endl;
        cout << "2. Insert at the beginning (prepend)" << endl;
        cout << "3. Insert at index" << endl;
        cout << "4. Delete first node" << endl;
        cout << "5. Delete last node" << endl;
        cout << "6. Delete node at index" << endl;
        cout << "7. Update node at index" << endl;
        cout << "8. Print List" << endl;
        cout << "9. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            ll.append(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            ll.prepend(data);
            break;
        case 3:
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter data: ";
            cin >> data;
            ll.insertAtIndex(index, data);
            break;
        case 4:
            ll.deleteFirstNode();
            break;
        case 5:
            ll.deleteLastNode();
            break;
        case 6:
            cout << "Enter index: ";
            cin >> index;
            ll.deleteAtIndex(index);
            break;
        case 7:
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter new data: ";
            cin >> data;
            ll.updateNodeAtIndex(index, data);
            break;
        case 8:
            ll.printList();
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "Wrong choice entered. Please enter a valid choice" << endl;
            Sleep(1000);
            break;
        }
    }
    return 0;
}