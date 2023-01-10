// Name: Sufiyaan Usmani
// Roll No: 21K-3195
// Section: BCS-3J

#include <iostream>
using namespace std;

void MinMax(int arr[], int size, int *min, int *max){
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++){
        if (arr[i] < *min){
            *min = arr[i];
        }
        if (arr[i] > *max){
            *max = arr[i];
        }
    }
}

int main(){
    int size, min, max;
    int arr[] = {5, 37, 3, 22, -4, 2, 3};

    size = sizeof(arr) / sizeof(arr[0]);
    MinMax(arr, size, &min, &max);

    cout << "Minimum Value: " << min << endl;
    cout << "Maximum Value: " << max << endl;
    return 0;
}
