// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Foo
{
private:
    int *p;
    int size;

public:
    // Parameterized Constructor
    Foo(int size, int f)
    {
        this->size = size;
        p = new int[size];
        for (int i = 0; i < size; i++)
        {
            p[i] = f;
        }
    }

    // Copy Constructor
    Foo(const Foo &obj)
    {
        size = obj.size;
        p = new int[size];
        for (int i = 0; i < size; i++)
        {
            p[i] = obj.p[i];
        }
    }

    // Copy Assignment Operator
    Foo &operator=(const Foo &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] p;
        this->size = other.size;
        p = new int[size];
        for (int i = 0; i < size; i++)
        {
            p[i] = other.p[i];
        }
        return *this;
    }

    void print()
    {
        cout << "p: " << p << endl;
        for (int i = 0; i < size; i++)
        {
            cout << p[i] << "  ";
        }
        cout << endl;
    }

    // Destructor
    ~Foo()
    {
        delete[] p;
        p = NULL;
    }
};

int main()
{
    Foo f(5, 9);
    f.print();
    // copy constructor
    Foo g(f);
    g.print();
    Foo h = g;
    h.print();
    Foo i(5, 1);
    i.print();
    // copy assignment operator
    i = g;
    i.print();

    return 0;
}