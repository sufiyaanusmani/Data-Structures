// Sufiyaan Usmani

#include <iostream>
using namespace std;

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n){
    int i, j, k;
    for(i=0;i<n-1;i++){
        k = i;
        for(j=i+1;j<n;j++){
            if(arr[j] < arr[k]){
                k = j;
            }
        }
        if(i != k){
            swap(arr[i], arr[k]);
        }
    }
}

void insertionSort(int arr[], int n){
    int i, j, temp;
    for(int i=1;i<n;i++){
        temp = arr[i];
        j = i - 1;
        while(j>-1 && temp < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void combSort(int arr[], int n){
    bool swapped = true;
    int gap = n;
    while(gap != 1 || swapped == true){
        gap = (int)(gap / 1.3);
        if(gap < 1){
            gap = 1;
        }
        swapped = false;
        for(int i=0;i<n-gap;i++){
            if(arr[i] > arr[i+gap]){
                swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
    }
}

void shellSort(int arr[], int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp = arr[i];
            int j;
            for(j=i;(j>=gap)&&(temp<arr[j-gap]);j-=gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

void merge(int arr[], int l, int m, int h){
    int i, j, k;
    i = l;
    j = m+1;
    k = l;
    int temp[100];
    while(i<=m && j<=h){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    for(;i<=m;i++){
        temp[k] = arr[i];
        k++;
    }
    for(;j<=h;j++){
        temp[k] = arr[j];
        k++;
    }
    for(int p=l;p<=h;p++){
        arr[p] = temp[p];
    }
}

void mergeSort(int arr[], int l, int h){
    if(l < h){
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}

int partition(int arr[], int l, int h){
    int pIndex = h;
    int pivot = arr[pIndex];
    int i = l - 1;
    for(int j=l;j<=h-1;j++){
        if(arr[j] < arr[pIndex]){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[pIndex]);
    return(i+1);
}

void quickSort(int arr[], int l, int h){
    if(l < h){
        int pIndex = partition(arr, l, h);
        quickSort(arr, l, pIndex - 1);
        quickSort(arr, pIndex+1, h);
    }
}

int main(){
    int arr[] = {2, 6, 2, 6, 2, 99, 1, 5, 34, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    // combSort(arr, n);
    // shellSort(arr, n);
    // mergeSort(arr, 0, n-1);
    quickSort(arr, 0, n-1);
    print(arr, n);
    return 0;
}