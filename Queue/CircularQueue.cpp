// Sufiyaan Usmani

#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int size;
    int *arr;
    int front;
    int rear;
    int currentSize;

public:
    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[this->size];
        front = rear = -1;
        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }
        currentSize = 0;
    }

    bool isEmpty()
    {
        if (currentSize == 0)
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
        if (currentSize == size)
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
            rear = (rear + 1) % size;
            arr[rear] = data;
            currentSize++;
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
            front = (front + 1) % size;
            data = arr[front];
            currentSize--;
        }
        return data;
    }

    void print()
    {
        if (currentSize == 0)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            int i = front + 1;
            do
            {
                if (arr[i] != -1)
                {
                    cout << arr[i] << "  ";
                }
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout << endl;
        }
    }
};

int main()
{
    CircularQueue queue(5);
    queue.print();
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
    queue.dequeue();
    queue.print();
    queue.enqueue(70);
    queue.print();
    return 0;
}