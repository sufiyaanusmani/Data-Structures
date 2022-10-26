// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int *arr;
    int front;
    int rear;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
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
        if (rear == size - 1)
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
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    int dequeue()
    {
        int data = -1;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else if (rear == front)
        {
            data = arr[front];
            arr[front] = 0;
            rear = front = -1;
        }
        else
        {
            data = arr[front];
            arr[front] = 0;
            front++;
        }
        return data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q(4);

    // print Queue elements
    q.display();

    // inserting elements in the queue
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // print Queue elements
    q.display();

    // insert element in the queue
    q.enqueue(60);

    // print Queue elements
    q.display();

    q.dequeue();
    q.dequeue();

    printf("\n\nafter two node deletion\n\n");

    // print Queue elements
    q.display();

    return 0;
}