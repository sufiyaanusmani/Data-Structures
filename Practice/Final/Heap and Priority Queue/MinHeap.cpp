// Sufiyaan Usmani

#include <iostream>
using namespace std;

class MinHeap{
    private:
        int *arr;
        int size;
        int capacity;
    public:
        MinHeap(int capacity){
            this->capacity = capacity;
            arr = new int[this->capacity];
            size = 0;
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

        int extractMin(){
            if(size == 0){
                cout << "Empty" << endl;
                return -1;
            }else if(size == 1){
                int data = arr[0];
                size--;
                return data;
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
            int smallest = i;
            if(left < size && arr[left] < arr[smallest]){
                smallest = left;
            }
            if(right < size && arr[right] < arr[smallest]){
                smallest = right;
            }
            if(smallest != i){
                swap(arr[smallest], arr[i]);
                heapify(smallest);
            }
        }

        void deleteData(int data){
            int index = getIndex(data);
            decreaseData(index, INT_MIN);
            extractMin();
        }

        int getIndex(int data){
            for(int i=0;i<size;i++){
                if(arr[i] == data){
                    return i;
                }
            }
            return -1;
        }

        void decreaseData(int index, int data){
            arr[index] = data;
            while(index != 0 && data < arr[parent(index)]){
                swap(arr[index], arr[parent(index)]);
                index = parent(index);
            }
        }
};

int main(){
    MinHeap heap(5);
    heap.insert(40);
    heap.insert(50);
    heap.insert(20);
    heap.insert(19);
    heap.printHeap();
    cout << heap.extractMin() << endl << endl;
    heap.printHeap();
    heap.deleteData(20);
    heap.printHeap();
    return 0;
}