// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int *arr;
    int rear;
    int front;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        rear = front = -1;
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
            rear = front = 0;
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
            rear = front = -1;
        }
        else
        {
            data = arr[front];
            front++;
        }
        return data;
    }

    int count()
    {
        return (rear - front + 1);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue queue(3);
    queue.display();
    queue.enqueue(10);
    queue.enqueue(20);
    queue.display();
    queue.enqueue(30);
    queue.enqueue(40);
    queue.display();
    queue.dequeue();
    queue.display();
    return 0;
}