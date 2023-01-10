// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 5

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void addMember(int data)
    {
        Node *n = new Node(data);
        if(n == NULL)
        {
            // acting as Queue capacity
            cout << "Heap Overflow" << endl;
            return;
        }
        else
        {
            if (isEmpty())
            {
                front = rear = n;
            }
            else
            {
                rear->next = n;
                rear = n;
            }
        }
    }

    int removeMember()
    {
        int data = -1;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            data = temp->data;
            delete temp;
        }
        return data;
    }
};

int main()
{
    Queue queue;
    queue.addMember(10);
    queue.addMember(20);
    queue.addMember(30);
    queue.print();
    queue.removeMember();
    queue.print();
    return 0;
}