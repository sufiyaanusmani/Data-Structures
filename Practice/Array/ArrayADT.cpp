#include <iostream>
using namespace std;

class Array
{
private:
    int *array;
    int capacity;
    int size;

public:
    // Constructor
    Array(int capacity = 10)
    {
        this->capacity = capacity;
        array = new (nothrow) int[this->capacity];
        size = 0;
    }

    // Copy Constructor
    Array(const Array &old)
    {
        capacity = old.capacity;
        size = old.size;
        array = new (nothrow) int[capacity];
        for (int i = 0; i < size; i++)
        {
            array[i] = old.array[i];
        }
    }

    // Assignment Operator
    Array operator=(const Array &old)
    {
        int i;
        if (this != &old)
        {
            size = old.size;
            capacity = old.capacity;

            delete[] array;
            array = new (nothrow) int[capacity];
            for (i = 0; i < size; i++)
            {
                array[i] = old.array[i];
            }
        }
        return *this;
    }

    bool isEmpty()
    {
        if (size == 0)
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
        if (size == capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Displaying Array
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
                cout << "  " << array[i];
            }
            cout << endl;
        }
    }

    // Access Operator []
    int operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw "Exception: Index out of bound";
        }
        return array[index];
    }

    // Appending value to the last of array
    void pushBack(int value)
    {
        if (isFull())
        {
            capacity = 2 * capacity;
            int *newArray = new (nothrow) int[capacity];
            for (int i = 0; i < size; i++)
            {
                newArray[i] == array[i];
            }
            delete[] array;
            array = newArray;
        }
        else
        {
            array[size] = value;
            size++;
        }
    }

    // Inserting value at a specific index
    void set(int index, int value)
    {
        if (index < 0 || index >= size)
        {
            cout << "Exception: Index out of bound";
        }
        else
        {
            array[index] = value;
        }
    }

    void remove(int index)
    {
        if (isEmpty())
        {
            cout << "Array is empty" << endl;
        }
        else if (index < 0 || index >= size)
        {
            cout << "Exception: Index out of bound" << endl;
        }
        else
        {
            for (int i = index; i < size - 1; i++)
            {
                array[i] = array[i + 1];
            }
            size--;
        }
    }

    int search(int value)
    {
        int index = -1;
        if (isEmpty())
        {
            cout << "Array is empty" << endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (array[i] == value)
                {
                    index = i;
                    break;
                }
            }
        }
        return index;
    }

    int get(int index)
    {
        if (isEmpty())
        {
            throw "Array is empty";
        }
        else if (index < 0 || index >= size)
        {
            throw "Exception: Index out of bound";
        }
        return array[index];
    }

    int max()
    {
        int largest = INT_MIN;
        if (isEmpty())
        {
            cout << "Array is empty" << endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (array[i] > largest)
                {
                    largest = array[i];
                }
            }
        }
        return largest;
    }

    int min()
    {
        int smallest = INT_MAX;
        if (isEmpty())
        {
            cout << "Array is empty" << endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (array[i] < smallest)
                {
                    smallest = array[i];
                }
            }
        }
        return smallest;
    }

    int sum()
    {
        int total = 0;
        if (isEmpty())
        {
            total = 0;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                total += array[i];
            }
        }
        return total;
    }

    float avg()
    {
        float a = sum() / (float)size;
        return a;
    }

    ~Array()
    {
        delete[] array;
    }
};

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    Array array1(size);
    array1.pushBack(6);
    array1.pushBack(1);
    array1.pushBack(9);
    array1.pushBack(1);
    array1.display();
    cout << endl
         << array1.max() << endl;
    cout << array1.min() << endl;
    return 0;
}