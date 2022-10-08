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
        if (front == NULL)
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

    void enqueue(int data)
    {
        Node *n = new Node(data);
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

    int dequeue()
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
    queue.print();
    queue.dequeue();
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.print();
    queue.enqueue(60);
    queue.print();
    queue.dequeue();
    queue.dequeue();
    queue.print();
    queue.enqueue(70);
    queue.print();
    return 0;
}