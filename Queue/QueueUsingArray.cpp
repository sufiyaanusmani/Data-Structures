// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *arr;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[this->size];
        front = rear = -1;
    }

    bool isEmpty()
    {
        if (front == rear)
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
        else
        {
            front++;
            data = arr[front];
        }
        return data;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for (int i = front + 1; i <= rear; i++)
            {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue queue(5);
    queue.print();
    queue.dequeue();
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.print();
    queue.enqueue(60);
    queue.dequeue();
    queue.dequeue();
    queue.print();
    queue.enqueue(70);
    queue.print();
    return 0;
}