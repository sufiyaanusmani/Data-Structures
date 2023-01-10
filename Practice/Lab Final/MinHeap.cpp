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

        bool isEmpty(){
            if(size == 0){
                return true;
            }else{
                return false;
            }
        }

        int parent(int i){
            return((i-1)/2);
        }

        int leftChild(int i){
            return((2*i)+1);
        }

        int rightChild(int i){
            return((2*i)+2);
        }

        int insert(int data){
            if(size == capacity){
                cout << "full" << endl;
            }else{
                size++;
                int i = size-1;
                arr[i] = data;
                while(i!=0 && data < arr[parent(i)]){
                    swap(arr[i], arr[parent(i)]);
                    i=parent(i);
                }
            }
        }

        void heapify(int i){
            int left = leftChild(i);
            int right = rightChild(i);
            int smallest = i;
            if(left<size && arr[left] < arr[smallest]){
                smallest = left;
            }
            if(right<size && arr[right] < arr[smallest]){
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
                arr[0] = arr[size-1];
                size--;
                heapify(0);
                return data;
            }
        }

        void deleteData(int data){
            int i = getIndex(data);
            decreaseKey(i, INT_MIN);
            extractMin();
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
            while(i!=0 && data < arr[parent(i)]){
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }
};

int main(){
    MinHeap heap(5);
    heap.insert(30);
    heap.insert(40);
    heap.insert(10);
    heap.insert(1);
    heap.insert(6);
    heap.deleteData(1);
    while(!heap.isEmpty()){
        cout << heap.extractMin() << "  ";
    }
    cout << endl;
    return 0;
}