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
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class CircularLinkedList
{
private:
    Node *tail;

public:
    CircularLinkedList()
    {
        tail = NULL;
    }

    void print()
    {
        if (tail == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = tail->next;
            do
            {
                cout << temp->data << "  ";
                temp = temp->next;
            } while (temp != tail->next);
            cout << endl;
        }
    }

    void prepend(int data)
    {
        Node *n = new Node(data);
        if (tail == NULL)
        {
            tail = n;
            tail->next = n;
        }
        else
        {
            n->next = tail->next;
            tail->next = n;
        }
    }

    void append(int data)
    {
        Node *n = new Node(data);
        if (tail == NULL)
        {
            tail = n;
            tail->next = n;
        }
        else
        {
            n->next = tail->next;
            tail->next = n;
            tail = n;
        }
    }

    void insert(int index, int data)
    {
        if (index == 0)
        {
            // if inserting at first node
            prepend(data);
        }
        else
        {
            Node *temp = tail->next;
            Node *prev = NULL;
            int count = 0;
            do
            {
                prev = temp;
                temp = temp->next;
                count++;
            } while (temp != tail->next && count != index);
            if (temp != tail->next)
            {
                if (temp == tail)
                {
                    // if inserting at last node
                    append(data);
                }
                else
                {
                    // if inserting
                    //     at any other position
                    Node *n = new Node(data);
                    n->next = temp;
                    prev->next = n;
                }
            }
            else
            {
                // if index greater than total number of nodes
                cout << "Invalid index" << endl;
            }
        }
    }

    bool isCircular()
    {
        Node *one = tail->next;
        Node *two = tail->next;
        while (one != NULL && two != NULL && two->next != NULL)
        {
            one = one->next;
            two = two->next->next;
            if (one == two)
            {
                return true;
            }
        }
        return false;
    }

    int count()
    {
        int total = 0;
        if (tail != NULL)
        {
            Node *temp = tail->next;
            do
            {
                total++;
                temp = temp->next;
            } while (temp != tail->next);
        }
        return total;
    }

    void reverse()
    {
        if (tail != NULL)
        {
            Node *p = tail->next;
            Node *q = NULL;
            Node *r = NULL;
            tail = tail->next;
            do
            {
                r = q;
                q = p;
                p = p->next;
                q->next = r;
            } while (p != tail);
            tail->next = q;
        }
    }

    void deleteFirstNode()
    {
        if (tail == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            // if only one node
            if (tail->next == tail)
            {
                delete tail;
                tail = NULL;
            }
            else
            {
                Node *temp = tail->next;
                tail->next = temp->next;
                delete temp;
            }
        }
    }

    void deleteLastNode()
    {
        if (tail == NULL)
        {
            cout << "empty" << endl;
        }
        else
        {
            // if only one node
            if (tail->next == tail)
            {
                delete tail;
                tail = NULL;
            }
            else
            {
                Node *temp = tail->next;
                Node *prev = NULL;
                do
                {
                    prev = temp;
                    temp = temp->next;
                } while (temp != tail);
                prev->next = tail->next;
                tail = prev;
                delete temp;
            }
        }
    }

    void deleteNode(int index)
    {
        if (tail == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            if (index == 0)
            {
                deleteFirstNode();
            }
            else
            {
                Node *temp = tail->next;
                Node *prev = NULL;
                int count = 0;
                do
                {
                    prev = temp;
                    temp = temp->next;
                    count++;
                } while (temp != tail->next && count != index);
                if (temp == tail && count == index)
                {
                    // if last node
                    deleteLastNode();
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                }
            }
        }
    }

    void removeDuplicates()
    {
        if (tail != NULL)
        {
            Node *temp1 = tail->next;
            do
            {
                for (Node *temp2 = tail->next; temp2 != tail; temp2 = temp2->next)
                {
                    if (temp1 != temp2 && temp1->data == temp2->data)
                    {
                        Node *n = temp2->next;
                        deleteNode(temp2);
                        temp2 = n;
                    }
                }
                temp1 = temp1->next;
            } while (temp1 != tail->next);
        }
    }

    void deleteNode(Node *n)
    {
        if (tail != NULL)
        {
            if (tail == n)
            {
                deleteLastNode();
            }
            else
            {
                if (n == tail->next)
                {
                    deleteFirstNode();
                }
                else
                {
                    Node *temp = tail->next;
                    Node *prev = NULL;
                    do
                    {
                        prev = temp;
                        temp = temp->next;
                        if (temp == n)
                        {
                            prev->next = temp->next;
                            delete temp;
                            break;
                        }
                    } while (temp != tail->next);
                }
            }
        }
    }
};

int main()
{
    CircularLinkedList cll;
    cll.prepend(10);
    cll.prepend(20);
    cll.prepend(30);
    cll.print();
    cll.append(40);
    cll.append(50);
    cll.append(60);
    cll.print();
    cll.insert(3, 70);
    cll.print();
    cout << cll.isCircular() << endl;
    cout << cll.count() << endl;
    cll.deleteFirstNode();
    cll.print();
    cll.deleteLastNode();
    cll.print();
    cll.deleteNode(3);
    cll.print();
    cout << cll.isCircular() << endl;
    cll.insert(4, 60);
    cll.print();
    cll.reverse();
    cll.print();
    cll.append(70);
    cll.append(20);
    cll.append(20);
    cll.append(30);
    cll.print();
    cll.removeDuplicates();
    cll.print();
    return 0;
}