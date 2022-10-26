// Sufiyaan Usmani

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
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    void printList()
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

    void prepend(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            n->next = head;
            head = n;
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

    void insert(int index, int data)
    {
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
            if (temp == NULL)
            {
                cout << "Invalid index" << endl;
            }
            else
            {
                Node *n = new Node(data);
                n->next = temp;
                prev->next = n;
            }
        }
    }

    int sum(Node *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        return (n->data) + sum(n->next);
    }

    void deleteFirstNode()
    {
        if (head == NULL)
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

    void deleteLastNode()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
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

    void deleteNode(int data)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            if (head->next == NULL && head->data == data)
            {
                delete head;
                head == NULL;
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
                    delete temp;
                }
                else
                {
                    cout << "Data not found" << endl;
                }
            }
        }
    }

    int count()
    {
        int total = 0;
        if (head != NULL)
        {
            Node *temp = head;
            while (temp != NULL)
            {
                temp = temp->next;
                total++;
            }
        }
        return total;
    }

    int countRecursive(Node *n)
    {
        // base case
        if (n == NULL)
        {
            return 0;
        }
        return 1 + countRecursive(n->next);
    }

    bool search(int data)
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

    bool searchRecursive(Node *n, int data)
    {
        if (n == NULL)
        {
            return false;
        }
        if (n->data == data)
        {
            return true;
        }
        searchRecursive(n->next, data);
    }

    void reverse()
    {
        if (head != NULL)
        {
            Node *p, *q, *r;
            p = head;
            q = r = NULL;
            while (p != NULL)
            {
                r = q;
                q = p;
                p = p->next;
                q->next = r;
            }
            head = q;
        }
    }

    void printMiddle()
    {
        int length = count();
        int mid = length / 2;
        Node *temp = head;
        for (int i = 0; i < mid; i++)
        {
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

    int countN(int data)
    {
        int count = 0;
        if (head != NULL)
        {
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp->data == data)
                {
                    count++;
                }
                temp = temp->next;
            }
        }
        return count;
    }

    bool isPalindrome()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            SinglyLinkedList sll;
            Node *temp = head;
            while (temp != NULL)
            {
                sll.append(temp->data);
                temp = temp->next;
            }
            sll.reverse();
            Node *temp2 = sll.head;
            temp = head;
            while (temp != NULL)
            {
                if (temp->data != temp2->data)
                {
                    return false;
                }
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        return true;
    }

    void moveLastToFront()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
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
            prepend(temp->data);
            delete temp;
        }
    }

    void removeDuplicates()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            for (Node *temp1 = head; temp1 != NULL; temp1 = temp1->next)
            {
                for (Node *temp2 = head; temp2->next != NULL; temp2 = temp2->next)
                {
                    if (temp1 != temp2 && temp1->data == temp2->data)
                    {
                        Node *n;
                        n = temp2->next;
                        deleteNode(temp2);
                        temp2 = n;
                    }
                }
            }
        }
    }

    void deleteNode(Node *n)
    {
        if (n == head)
        {
            deleteFirstNode();
        }
        else if (n->next == NULL)
        {
            deleteLastNode();
        }
        else
        {
            Node *temp = head;
            while (temp->next != n)
            {
                temp = temp->next;
            }
            temp->next = n->next;
            delete n;
        }
    }

    bool isSorted(Node *n)
    {
        if (n->next == NULL)
        {
            return true;
        }
        if (n->data > n->next->data)
        {
            return false;
        }
        isSorted(n->next);
    }

    int countUnique()
    {
        int total = 0;
        int extra;
        for (Node *temp = head; temp->next->next != NULL; temp = temp->next)
        {
            extra = 0;
            for (Node *j = temp->next; j->next != NULL; j = j->next)
            {
                if (temp->data == j->data)
                {
                    extra++;
                }
            }
            if (extra > 0)
            {
                total++;
            }
        }
        return total;
    }

    void merge(SinglyLinkedList &sll1)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = sll1.head;
    }

    void swap1(int index1, int index2)
    {
        Node *temp1 = head;
        int count = 0;
        while (temp1 != NULL && count < index1)
        {
            temp1 = temp1->next;
            count++;
        }

        Node *temp2 = head;
        count = 0;
        while (temp2 != NULL && count < index2)
        {
            temp2 = temp2->next;
            count++;
        }

        swap(temp1->data, temp2->data);
    }
};

int main()
{
    SinglyLinkedList sll;
    sll.prepend(10);
    sll.prepend(20);
    sll.printList();
    sll.append(50);
    sll.append(60);
    sll.printList();
    sll.insert(2, 15);
    sll.printList();
    sll.deleteFirstNode();
    sll.printList();
    sll.deleteLastNode();
    sll.printList();
    sll.deleteNode(15);
    sll.printList();
    cout << sll.count() << endl;
    cout << sll.countRecursive(sll.head) << endl;
    sll.append(70);
    sll.append(60);
    sll.append(80);
    sll.append(90);
    sll.prepend(70);
    sll.append(90);
    sll.prepend(45);
    sll.printList();
    cout << sll.search(70) << endl;
    cout << sll.search(75) << endl;
    cout << sll.searchRecursive(sll.head, 70) << endl;
    cout << sll.searchRecursive(sll.head, 75) << endl;
    sll.printList();
    sll.reverse();
    sll.printList();
    sll.printMiddle();
    cout << sll.countN(70) << endl;
    cout << sll.isPalindrome() << endl;
    sll.printList();
    sll.moveLastToFront();
    sll.printList();
    // sll.removeDuplicates();
    sll.printList();
    cout << sll.countUnique() << endl;
    SinglyLinkedList sll2;
    sll2.append(10);
    sll2.append(86);
    sll2.append(50);
    sll2.append(20);
    sll2.printList();
    sll.merge(sll2);
    sll.printList();
    sll.swap1(2, 5);
    sll.printList();
    cout << sll.isSorted(sll.head) << endl;
    SinglyLinkedList sll3;
    sll3.append(10);
    sll3.append(20);
    sll3.append(80);
    sll3.printList();
    cout << sll3.isSorted(sll3.head) << endl;
    sll.printList();
    cout << sll.countUnique() << endl;
    sll.printList();
    sll.insert(13, 99);
    sll.printList();
    cout << sll.sum(sll.head) << endl;
    return 0;
}