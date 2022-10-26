// Sufiyaan Usmani

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
public:
    Node *head, *sorted;
    SinglyLinkedList()
    {
        head = NULL;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "Empty" << endl;
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

    void prepend(int data)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
    }

    void insertAfter(int index, int data)
    {
        Node *n = new Node(data);
        int count = 0;
        Node *temp = head;
        while (temp != NULL && count != index)
        {
            count++;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            if (temp->next == NULL)
            {
                append(data);
            }
            else
            {
                n->next = temp->next;
                temp->next = n;
            }
        }
        else
        {
            cout << "Invalid Index" << endl;
        }
    }

    void deleteFirstNode()
    {
        if (head == NULL)
        {
            cout << "Empty" << endl;
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
            cout << "Empty" << endl;
        }
        else
        {
            if (head->next == NULL)
            {
                delete head;
                head = NULL;
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
    }

    void deleteNode(int index)
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
            while (temp != NULL && count != index)
            {
                count++;
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
                cout << "Invalid index" << endl;
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
                total++;
                temp = temp->next;
            }
        }
        return total;
    }

    int countRecursive(Node *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        return 1 + countRecursive(n->next);
    }

    void reverse()
    {
        if (head != NULL)
        {
            Node *p, *q, *r;
            p = head;
            q = NULL;
            r = NULL;
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

    void concatenate(SinglyLinkedList &another)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = another.head;
    }

    void removeDuplicates()
    {
        if (head != NULL)
        {
            for (Node *i = head; i->next->next != NULL; i = i->next)
            {
                Node *j;
                for (j = i->next; j->next != NULL; j = j->next)
                {
                    if (i->data == j->data)
                    {
                        Node *temp = j->next;
                        deleteNode(j);
                        j = temp;
                    }
                }
                if (i->data == j->data)
                {
                    deleteNode(j);
                }
            }
        }
    }

    void deleteNode(Node *n)
    {
        Node *temp = head;
        while (temp->next != n)
        {
            temp = temp->next;
        }
        temp->next = n->next;
        delete n;
    }

    void reverse(int start, int end)
    {
        Node *n1 = getNode(start);
        Node *n2 = getNode(end);
        Node *n3 = NULL;
        Node *prev = NULL;
        int temp;
        for (int i = start; i < end; i++)
        {
            prev = NULL;
            n3 = n1;
            while (n3 != n2)
            {
                prev = n3;
                temp = n3->data;
                n3->data = n3->next->data;
                n3->next->data = temp;
                n3 = n3->next;
            }
            n2 = prev;
        }
    }

    Node *getNode(int index)
    {
        Node *temp = head;
        int count = 0;
        while (count != index)
        {
            temp = temp->next;
            count++;
        }
        return temp;
    }

    bool isPalindrome()
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
        return true;
    }

    void printReverse(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        printReverse(n->next);
        cout << n->data << "  ";
    }

    // void bubbleSort()
    // {
    //     int temp1;
    //     for (int i = 0; i < count() - 1; i++)
    //     {
    //         Node *temp = head;
    //         for (int j = 0; j < count() - 1 - i; j++)
    //         {
    //             if (temp->data > temp->next->data)
    //             {
    //                 temp1 = temp->data;
    //                 temp->data = temp->next->data;
    //                 temp->next->data = temp1;
    //             }
    //             temp = temp->next;
    //         }
    //     }
    // }

    void rearrange()
    {
        SinglyLinkedList even, odd;
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (count % 2 == 0)
            {
                even.append(temp->data);
            }
            else
            {
                odd.append(temp->data);
            }
            count++;
            temp = temp->next;
        }

        temp = odd.head;
        while (temp != NULL)
        {
            even.append(temp->data);
            temp = temp->next;
        }
        head = even.head;
    }

    void insertionSort()
    {
        sorted = NULL;
        Node *next, *current;
        current = head;
        while (current != NULL)
        {
            next = current->next;
            sortedInsert(current);
            current = next;
        }
        head = sorted;
    }

    void sortedInsert(Node *n)
    {
        if (sorted == NULL || sorted->data >= n->data)
        {
            n->next = sorted;
            sorted = n;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < n->data)
            {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }

    void insertMiddle(int data)
    {
        Node *n = new Node(data);
        Node *temp = head;
        for (int i = 0; i < (count() / 2) - 1; i++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }

    void printMiddle()
    {
        Node *temp = head;
        for (int i = 0; i < (count() / 2); i++)
        {
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

    void deleteAlternate()
    {
        Node *prev = head;
        Node *node = head->next;
        while (prev != NULL && node != NULL)
        {
            prev->next = node->next;
            delete node;
            prev = prev->next;
            if (prev != NULL)
            {
                node = prev->next;
            }
        }
    }

    void rotateLeft(int k)
    {
        int data;
        for (int i = 0; i < k; i++)
        {
            data = head->data;
            deleteFirstNode();
            append(data);
        }
    }

    void bubbleSort()
    {
        Node *temp;
        int n;
        for (int i = 0; i < count() - 1; i++)
        {
            temp = head;
            for (int j = 0; j < count() - 1 - i; j++)
            {
                if (temp->data > temp->next->data)
                {
                    n = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = n;
                }
                temp = temp->next;
            }
        }
    }
};

int main()
{
    SinglyLinkedList sll;
    sll.append(10);
    sll.append(20);
    sll.print();
    sll.insertAfter(1, 30);
    sll.insertAfter(1, 40);
    sll.print();
    sll.deleteNode(3);
    sll.print();
    sll.append(10);
    // sll.append(80);
    sll.prepend(55);
    sll.print();
    cout << sll.count() << endl;
    cout << sll.countRecursive(sll.head) << endl;
    sll.print();
    sll.reverse();
    sll.print();
    SinglyLinkedList sll2;
    sll2.append(44);
    sll2.append(88);
    // sll2.append(80);
    sll2.print();
    sll.concatenate(sll2);
    sll.print();
    sll.removeDuplicates();
    sll.print();
    sll.reverse(2, 5);
    sll.print();
    cout << sll.isPalindrome() << endl;
    sll.printReverse(sll.head);
    // sll.bubbleSort2();
    cout << endl;
    sll.print();
    sll.rearrange();
    sll.print();
    sll.insertionSort();
    sll.print();
    sll.insertMiddle(555);
    sll.print();
    cout << sll.count() << endl;
    sll.printMiddle();
    // sll.deleteAlternate();
    sll.print();
    sll.rotateLeft(4);
    sll.print();
    sll.bubbleSort();
    sll.print();
    cout << "end" << endl;
    return 0;
}