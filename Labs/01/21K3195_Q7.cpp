// Name: Sufiyaan Usmani
// Roll No: 21K-3195
// Section: BCS-3J

#include <iostream>
using namespace std;

class Numbers{
private:
    int size;
    int *ptr;

public:
    // Default Constructor
    Numbers() {}

    // Parameterized Constructor
    Numbers(int size){
        this->size = size;
        ptr = new int[size];
    }

    // Copy Constructor
    Numbers(const Numbers &old){
        size = old.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++){
            ptr[i] = old.ptr[i];
        }
    }

    // Copy Assignment Operator
    Numbers &operator=(const Numbers &old){
        size = old.size;
        // Deleting if previously allocated to release old resources
        delete[] ptr;
        ptr = new int[size];
        for (int i = 0; i < size; i++){
            ptr[i] = old.ptr[i];
        }
        return *this;
    }

    void setSize(int size){
        this->size = size;
        ptr = new int[size];
    }

    // Funtion to store values
    void inputValues(){
        int i;
        for (i = 0; i < size; i++){
            cout << "Enter value for index " << i << ": ";
            cin >> ptr[i];
        }
    }

    // Funtion to print values
    void printValues(){
        for (int i = 0; i < size; i++){
            cout << ptr[i] << "  ";
        }
        cout << endl;
    }

    // Destructor
    ~Numbers(){
        delete[] ptr;
    }
};

int main(){
    Numbers n1(5);
    n1.inputValues();
    cout << endl << "n1: ";
    n1.printValues();

    // Using copy constructor (deep copy)
    Numbers n2(n1);
    cout << "n2: ";
    n2.printValues();

    // Using copy assignment operator (deep copy)
    Numbers n3 = n1;
    cout << "n3: ";
    n3.printValues();
    
    return 0;
}
