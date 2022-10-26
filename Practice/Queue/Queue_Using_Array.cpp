#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int size;
    int front; // to perform deletion
    int rear;  // to perform insertion
public:
    Queue(int size = 10)
    {
        this->size = size;
        arr = new int[this->size];
        front = rear = -1;
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
                rear = front = 0;
                arr[rear] = value;
            }
            else
            {
                rear++;
                arr[rear] = value;
            }
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
                arr[front] = INT_MIN;
                front++;
            }
        }
        return value;
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
                cout << arr[i] << endl;
            }
        }
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q;
    cout << "Enqueue 10, 20, and 30 to the Queue." << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Count: " << q.count() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "isEmpty: " << q.isEmpty() << endl;
    q.display();
    return 0;
}