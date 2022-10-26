// Sufiyaan Usmani

#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int size;
    int *arr;
    int count;
    int front;
    int rear;

public:
    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        count = 0;
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
        if ((rear + 1) % size == front)
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
            count++;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = data;
            count++;
        }
    }

    int dequeue()
    {
        int data = -1;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else if (front == rear)
        {
            data = arr[front];
            front = rear = -1;
            count--;
        }
        else
        {
            data = arr[front];
            arr[front] = 0;
            front = (front + 1) % size;
            count--;
        }
        return data;
    }

    int getCount()
    {
        return count;
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
    CircularQueue cq(3);
    cq.display();
    cq.enqueue(10);
    cq.enqueue(20);
    cq.display();
    cq.dequeue();
    cq.display();
    cq.enqueue(30);
    cq.enqueue(40);
    cq.display();
    cq.enqueue(50);
    cq.display();
    return 0;
}