// Sufiyaan Usmani

#include <iostream>
using namespace std;

class MaxHeap{
    private:
        int *arr;
        int capacity;
        int size;
    public:
        MaxHeap(int capacity){
            this->capacity = capacity;
            arr = new int[this->capacity];
            this->size = 0;
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

        void insert(int data){
            if(capacity == size){
                cout << "Heap is full" << endl;
            }else{
                size++;
                int i = size - 1;
                arr[i] = data;
                while(i != 0 && arr[i] > arr[parent(i)]){
                    swap(arr[i], arr[parent(i)]);
                    i = parent(i);
                }
            }
        }

        int extractMax(){
            if(size == 0){
                cout << "Empty" << endl;
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

        void heapify(int i){
            int left = leftChild(i);
            int right = rightChild(i);
            int largest = i;
            if(left < size && arr[left] > arr[largest]){
                largest = left;
            }
            if(right < size && arr[right] > arr[largest]){
                largest = right;
            }
            if(largest != i){
                swap(arr[largest], arr[i]);
                heapify(largest);
            }
        }

        void deleteData(int data){
            int index = getIndex(data);
            increaseKey(index, INT_MAX);
            extractMax();
        }

        int getIndex(int data){
            for(int i=0;i<size;i++){
                if(arr[i] == data){
                    return i;
                }
            }
            return -1;
        }
        
        void increaseKey(int index, int data){
            arr[index] = data;
            while(index != 0 && arr[index] > arr[parent(index)]){
                swap(arr[index], arr[parent(index)]);
                index = parent(index);
            }
        }

        ~MaxHeap(){
            delete[] arr;
            arr = NULL;
        }
};

int main(){
    MaxHeap heap(4);
    heap.insert(4);
    heap.insert(8);
    heap.insert(2);
    heap.insert(10);
    heap.printHeap();
    cout << endl;
    // heap.extractMax();
    heap.deleteData(4);
    heap.printHeap();
    return 0;
}