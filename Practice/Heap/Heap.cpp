#include <iostream>
using namespace std;
#define size 10

class Heap
{
private:
    int *arr;
    int current;

public:
    Heap()
    {
        arr = new int[size];
        current = 0;
    }

    int parent(int i)
    {
        return ((i - 1) / 2);
    }

    int leftChild(int i)
    {
        return ((2 * i) + 1);
    }

    int rightChild(int i)
    {
        return ((2 * i) + 2);
    }

    void insertElement(int data)
    {
        current++;
        arr[current] = data;
        int i, temp;
        i = current - 1;
    }
};

int main()
{

    return 0;
}