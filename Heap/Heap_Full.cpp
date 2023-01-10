// Sufiyaan Usmani

#include <iostream>
using namespace std;

class MinHeap{
    private:
        int size;
        int capacity;
        int *arr;
    public:
        MinHeap(int capacity){
            this->capacity = capacity;
            size = 0;
            arr = new int[capacity];
        }

        MinHeap(int a[], int n){
            this->capacity = n;
            size = 0;
            arr = new int[n];
            for(int i=0;i<n;i++){
                insert(a[i]);
            }
        }

        int parent(int i){
            return((i - 1) / 2);
        }

        int leftChild(int i){
            return((2 * i) + 1);
        }

        int rightChild(int i){
            return((2 * i) + 2);
        }

        void insert(int data){
            if(size == capacity){
                cout << "Full" << endl;
            }else{
                size++;
                int i = size - 1;
                arr[i] = data;
                while(i != 0 && data < arr[parent(i)]){
                    swap(arr[i], arr[parent(i)]);
                    i = parent(i);
                }
            }
        }

        void heapify(int i){
            int left = leftChild(i);
            int right = rightChild(i);
            int smallest = i;
            if(left < size && arr[left] < arr[smallest]){
                smallest = left;
            }
            if(right < size && arr[right] < arr[smallest]){
                smallest = right;
            }
            if(i != smallest){
                swap(arr[i], arr[smallest]);
                heapify(smallest);
            }
        }

        int extractMin(){
            if(size == 0){
                return -1;
            }else if(size == 1){
                size--;
                return arr[0];
            }else{
                int data = arr[0];
                arr[0] = arr[size - 1];
                size--;
                heapify(0);
                return data;
            }
        }

        int getIndex(int data){
            for(int i=0;i<size;i++){
                if(arr[i] == data){
                    return i;
                }
            }
        }

        void decreaseKey(int i, int data){
            arr[i] = data;
            while(i != 0 && arr[i] < arr[parent(i)]){
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }

        void deleteData(int data){
            int i = getIndex(data);
            decreaseKey(i, INT_MIN);
            extractMin();
        }

        void heapSort(int arr[], int n){
            MinHeap heap(arr, n);
            for(int i=0;i<n;i++){
                arr[i] = heap.extractMin();
            }
        }

        bool isMinHeap(int arr[], int n){
            for(int i=(n-2)/2;i>=0;i--){
                if(arr[i] < arr[parent(i)]){
                    return false;
                }
            }
            return true;
        }

        void printHeap(){
		    int power = 0;
		    int value = 1;
		    for(int i = 0; i < size; i++){
		        if(i == value){
		            cout << endl;
		            power += 1;
		            value += (1 << power);
		        }
		        cout << arr[i] << "  ";
		    }
		    cout << endl;
		}
};

int main(){
    MinHeap heap(5);
    heap.insert(1);
    heap.insert(3);
    heap.insert(2);
    heap.insert(48);
    heap.printHeap();
    int arr[] = {7, 2, 1, 5, 9, 3, 89, 323};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << endl;
    cout << heap.isMinHeap(arr, n) << endl;
    heap.heapSort(arr, n);
    for(int i=0;i<n;i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
    cout << heap.isMinHeap(arr, n) << endl;
    return 0;
}