// Sufiyaan Usmani

#include <iostream>
#include <vector>
using namespace std;

// Vectors are the same as dynamic arrays with the ability to resize itself 
// automatically when an element is inserted or deleted, with their storage being 
// handled automatically by the container

int main(){
    // declaring vector(array) of int
    vector<int> arr;

    for(int i=0;i<5;i++){
        // appending (push back)
        arr.push_back(i);
    }

    // printing size of vector
    cout << "Size: " << arr.size() << endl;

    // resizes the vector size to 4
    arr.resize(4);
 
    // prints the vector size after resize()
    cout << "\nSize : " << arr.size();

     // checks if the vector is empty or not
    if (arr.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    // printing elements
     cout << "\nVector elements are: ";
    for (auto it = arr.begin(); it != arr.end(); it++)  // it acts as pointer
        cout << *it << " ";

    cout << endl;
    // accessing elements
    for(int i=0;i<arr.size();i++){
        cout << "Element at index: " << i << ": " << arr.at(i) << endl;
    }

    // getting first element
    cout << "First element: " << arr.front() << endl;

    // getting last element
    cout << "Last element: " << arr.back() << endl;

    // Modifiers
    vector<int> v;

    // filling array with 10, 5 times
    v.assign(5, 10);

    // printing vector
    for(int i=0;i<v.size();i++){
        cout << v.at(i) << endl;
    }

    // inserts 15 to the last position
    v.push_back(15);

    // removes last element
    v.pop_back();

    // inserts 5 at the beginning
    v.insert(v.begin(), 5);

    // removes the first element
    v.erase(v.begin());

    
    return 0;
}