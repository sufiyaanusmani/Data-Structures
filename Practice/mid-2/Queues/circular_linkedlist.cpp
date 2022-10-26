// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class CircularQueue
{
private:
    Node *front, *rear;

public:
    CircularQueue()
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
            rear->next = front;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            if (front == rear)
            {
                delete front;
                front = rear = NULL;
            }
            else
            {
                Node *temp = front;
                front = front->next;
                rear->next = front;
                delete temp;
            }
        }
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
            do
            {
                cout << temp->data << "  ";
                temp = temp->next;
            } while (temp != front);
            cout << endl;
        }
    }
};

int main()
{
    CircularQueue q;
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}