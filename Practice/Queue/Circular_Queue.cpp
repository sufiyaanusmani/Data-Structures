#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int *arr;
    int front;
    int rear;
    int count;

public:
    Queue(int size = 10)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
        count = 0;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if ((rear + 1) % size == front)
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
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
                arr[rear] = value;
            }
            else
            {
                rear = (rear + 1) % size;
                arr[rear] = value;
            }
            count++;
        }
    }

    int dequeue()
    {
        int value = -1;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            value = arr[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
            count--;
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
            int i = front, c = 0;
            while (c < count)
            {
                cout << "  " << arr[i];
                i = (i + 1) % size;
                c++;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q;
    cout << "Enqueue 10, 20, 30 and 40 to the Queue." << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << "isFull: " << q.isFull() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Enqueue 50: " << endl;
    q.enqueue(50);
    cout << "isEmpty: " << q.isEmpty() << endl;
    q.display();
    return 0;
}