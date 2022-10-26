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

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue()
    {
        int value = INT_MIN;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            value = temp->data;
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            delete temp;
        }
        return value;
    }

    void display()
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
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Queue q;
    cout << "Enqueue 10, 20, and 30 to the Queue." << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "isEmpty: " << q.isEmpty() << endl;
    q.display();
    return 0;
}