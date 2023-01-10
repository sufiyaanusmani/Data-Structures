// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 1 to 6

#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;

// Task 1
// Implementing account information in bank
class Node
{
public:
    int accountNumber; // used as key
    string name;
    int amount;

    Node *next;

    Node()
    {
        accountNumber = 0;
        name = "";
        amount = 0;
        next = NULL;
    }

    Node(int accountNumber, string name, int amount)
    {
        this->accountNumber = accountNumber;
        this->name = name;
        this->amount = amount;
        next = NULL;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    // func to check if list is empty
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

    // Task 2
    Node *nodeExists(int accountNumber)
    {
        Node *p = head;
        while (p != NULL)
        {
            if (p->accountNumber == accountNumber)
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }

    void append(Node *n)
    {
        if (nodeExists(n->accountNumber) != NULL)
        {
            cout << "This node already exists with account number: " << n->accountNumber << endl;
        }
        else
        {
            // checking if list is already empty
            if (isEmpty())
            {
                head = n;
            }
            else
            {
                Node *p = head;
                while (p->next != NULL)
                {
                    p = p->next;
                }
                p->next = n;
            }
            cout << "Appended successfully" << endl;
        }
        Sleep(1500);
    }

    // Task 3
    void prepend(Node *n)
    {
        if (nodeExists(n->accountNumber) != NULL)
        {
            cout << "Node already exists with account number" << n->accountNumber << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Prepended Successfully" << endl;
        }
    }

    // Task 4
    void insertNodeAfter(int accountNumber, Node *n)
    {
        Node *p = nodeExists(accountNumber);
        if (p == NULL)
        {
            cout << "Node does not exists with given key" << endl;
        }
        else
        {
            if (nodeExists(n->accountNumber) != NULL)
            {
                cout << "Given account number already exists" << endl;
            }
            else
            {
                // assigning next of new node to next of given node
                n->next = p->next;

                // assigning next of given node to new node
                p->next = n;

                cout << "Inserted successfully" << endl;
            }
        }
    }

    // Task 5
    void deleteNode(int accountNumber)
    {
        // checking if list is already empty
        if (isEmpty())
        {
            cout << "Linked list is already empty" << endl;
        }
        else
        {
            Node *p = head;
            Node *previous = NULL;
            while (p != NULL && p->accountNumber != accountNumber)
            {
                previous = p;
                p = p->next;
            }
            if (p != NULL)
            {
                previous->next = p->next;
                delete p;
            }
            else
            {
                cout << "Account number " << accountNumber << " not found" << endl;
            }
        }
    }

    void deleteFirstNode()
    {
        // checking if list is empty
        if (isEmpty())
        {
            cout << "Linked list is empty" << endl;
        }
        else
        {
            Node *p = head;
            head = head->next;
            delete p;
        }
    }

    void deleteLastNode()
    {
        // checking if list is empty
        if (isEmpty())
        {
            cout << "Linked list is empty" << endl;
        }
        else
        {
            Node *p = head;
            while (p->next->next != NULL)
            {
                p = p->next;
            }
            Node *lastNode = p->next;
            p->next = NULL;
            delete lastNode;
        }
    }

    // Task 6
    // this function will update user's amount
    void updateNode(int accountNumber, int newAmount)
    {
        // as we have alredy checked new amount in main, this function will always receive a positive amount
        Node *p = nodeExists(accountNumber);
        if (p != NULL)
        {
            p->amount = newAmount;
            cout << "Amount updated successfully" << endl;
            Sleep(1000);
        }
        else
        {
            cout << "Given node (account) does not exist" << endl;
        }
    }

    // Printing all nodes
    void printList()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            Sleep(1000);
        }
        else
        {
            Node *p = head;
            while (p != NULL)
            {
                cout << "Account Number: " << p->accountNumber << endl;
                cout << "Name: " << p->name << endl;
                cout << "Amount: Rs. " << p->amount << endl << endl;
                p = p->next;
            }
            cout << "\n\nPress any key to continue...";
            getch();
        }
    }

    // Destructor
    ~SinglyLinkedList()
    {
        if (!isEmpty())
        {
            Node *p = head;
            while (p != NULL)
            {
                head = p;
                p = p->next;
                delete head;
            }
        }
        head = NULL;
    }
};

int main()
{
    SinglyLinkedList accounts;
    int accountNumber, amount, choice, acc;
    string name;
    Node *n;

    while (1)
    {
        system("cls");
        cout << "1. Append" << endl;
        cout << "2. Prepend" << endl;
        cout << "3. Insert After" << endl;
        cout << "4. Delete from head" << endl;
        cout << "5. Delete from tail" << endl;
        cout << "6. Delete node by account number" << endl;
        cout << "7. Update node (amount)" << endl;
        cout << "8. Print list (account information)" << endl;
        cout << "9. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case 1:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter name: ";
            cin >> name;
            do
            {
                cout << "Enter amount: ";
                cin >> amount;
                if (amount < 0) // to ensure only positive value is entered
                {
                    cout << "Error: Please enter a valid amount" << endl;
                }
            } while (amount < 0);
            n = new Node(accountNumber, name, amount);
            accounts.append(n);
            break;
        case 2:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter name: ";
            cin >> name;
            do
            {
                cout << "Enter amount: ";
                cin >> amount;
                if (amount < 0)
                {
                    cout << "Error: Please enter a valid amount" << endl;
                }
            } while (amount < 0);
            n = new Node(accountNumber, name, amount);
            accounts.prepend(n);
            break;
        case 3:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter name: ";
            cin >> name;
            do
            {
                cout << "Enter amount: ";
                cin >> amount;
                if (amount < 0)
                {
                    cout << "Error: Please enter a valid amount" << endl;
                }
            } while (amount < 0);
            n = new Node(accountNumber, name, amount);
            cout << "Enter account number after which you want to insert node: ";
            cin >> acc;
            accounts.insertNodeAfter(acc, n);
            break;
        case 4:
            accounts.deleteFirstNode();
            break;
        case 5:
            accounts.deleteLastNode();
            break;
        case 6:
            cout << "Enter account number you want to delete: ";
            cin >> acc;
            accounts.deleteNode(acc);
            break;
        case 7:
            cout << "Enter account number: ";
            cin >> acc;
            do
            {
                cout << "Enter new amount: ";
                cin >> amount;
                if (amount < 0)
                {
                    cout << "Error: Please enter a valid amount" << endl;
                }
            } while (amount < 0);
            accounts.updateNode(acc, amount);
            break;
        case 8:
            accounts.printList();
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "Error: Please enter a valid choice" << endl;
            break;
        }
    }
    return 0;
}
