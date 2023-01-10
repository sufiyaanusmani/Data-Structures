// Name: Sufiyaan Usmani
// Roll No: 21K-3195
// Section: BCS-3J

#include <iostream>
#include <string>
using namespace std;

class Animal{
private:
    string name;

public:
    void setName(string name){
        this->name = name;
    }

    string getName(){
        return name;
    }
};

void sort(Animal *arr, int size){
    int round, i;
    Animal temp;
    for (round = 0; round < size - 1; round++){
        for (i = 0; i < size - 1 - round; i++){
            if (arr[i].getName() > arr[i + 1].getName()){
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int main(){
    Animal *obj;
    obj = new Animal[5];
    int i;

    // Setting values
    obj[0].setName("Snake");
    obj[1].setName("Cat");
    obj[2].setName("Cow");
    obj[3].setName("Deer");
    obj[4].setName("Dog");

    // Printing array before sorting
    cout << "Before Sorting: " << endl;
    for (i = 0; i < 5; i++){
        cout << obj[i].getName() << endl;
    }

    // Sorting
    sort(obj, 5);

    cout << endl << endl << "After sorting: " << endl;
    // Printing animals in ascending order (after sorting)
    for (i = 0; i < 5; i++){
        cout << obj[i].getName() << endl;
    }

    // Deleting dynamically allocated array
    delete[] obj;
    return 0;
}
