// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 7

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

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
    SinglyLinkedList()
    {
        head = NULL;
    }

    // function that will modify linked list
    // this function will traverse through the list
    // if data in a node is odd, new node will be appended and current node will be deleted
    // This is all the odd numbers will move to the end
    void modify()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            int totalNodes = getNodeCount();
            int oddCount = getOddCount();

            // linked list will only be modified if list contains both even and odd numbers
            if (oddCount > 0 && oddCount < totalNodes)
            {
                Node *temp = head;
                Node *toDelete = NULL;
                for (int i = 0; i < oddCount;)
                {
                    if (temp->data % 2 == 1)
                    {
                        append(temp->data);
                        toDelete = temp;
                        temp = temp->next;
                        deleteNode(toDelete);
                        i++;
                        continue;
                    }
                    temp = temp->next;
                }
            }
        }
    }

    // this function will return total number of nodes in the list
    int getNodeCount()
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

    // This function will return total number of odd numbers in the list
    int getOddCount()
    {
        int count = 0;
        if (!isEmpty())
        {
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp->data % 2 == 1)
                {
                    count++;
                }
                temp = temp->next;
            }
        }
        return count;
    }

    // other functions of linked list
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

    void append(int data)
    {
        Node *n = new Node(data);
        if (isEmpty())
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

    void insertAfter(int data, int newData)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *n = new Node(data);
            Node *temp = head;
            while (temp->data != data)
            {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }

    void deleteFirstNode()
    {
        if (!isEmpty())
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteNode(Node *n)
    {
        if (head == n)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node *temp = head;
            Node *prev = NULL;
            while (temp != n)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
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
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    // Destructor
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
    // Using sample inputs given in question

    // List 1
    SinglyLinkedList list1;
    list1.append(17);
    list1.append(15);
    list1.append(8);
    list1.append(12);
    list1.append(10);
    list1.append(5);
    list1.append(4);
    list1.append(1);
    list1.append(7);
    list1.append(6);
    cout << "Original List: ";
    list1.printList();
    list1.modify();
    cout << "Modified List: ";
    list1.printList();
    cout << endl;

    // List 2
    SinglyLinkedList list2;
    list2.append(8);
    list2.append(12);
    list2.append(10);
    list2.append(5);
    list2.append(4);
    list2.append(1);
    list2.append(6);
    cout << "Original List: ";
    list2.printList();
    list2.modify();
    cout << "Modified List: ";
    list2.printList();
    cout << endl;

    // List 3
    SinglyLinkedList list3;
    list3.append(8);
    list3.append(12);
    list3.append(10);
    cout << "Original List: ";
    list3.printList();
    list3.modify();
    cout << "Modified List: ";
    list3.printList();
    cout << endl;

    // List 4
    SinglyLinkedList list4;
    list4.append(1);
    list4.append(3);
    list4.append(5);
    list4.append(7);
    cout << "Original List: ";
    list4.printList();
    list4.modify();
    cout << "Modified List: ";
    list4.printList();
    cout << endl;

    return 0;
}