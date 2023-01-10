#include <iostream>
using namespace std;

class MaxHeap{
	private:
		int capacity;
		int size;
		int *arr;
	public:
		MaxHeap(int capacity){
			this->capacity = capacity;
			size = 0;
			arr = new int[this->capacity];
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
			if(capacity == size){
				cout << "Heap is full" << endl;
				return;
			}
			size++;
			int i = size - 1;
			arr[i] = data;
			
			while(i != 0 && arr[i] > arr[parent(i)]){
				swap(arr[i], arr[parent(i)]);
				i = parent(i);
			}
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
			while(index != 0 && data > arr[parent(index)]){
				swap(arr[index], arr[parent(index)]);
				index = parent(index);
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
				swap(arr[i], arr[largest]);
				heapify(largest);
			}
		}

        void sort(){
            int n = size;
            int *temp = new int[n];
            for(int i=0;i<n;i++){
                temp[i] = extractMax();
            }

            // printing sorted array
            for(int i=n-1;i>=0;i--){
                cout << temp[i] << "  ";
            }
            cout << endl;
            delete[] temp;
        }

		~MaxHeap(){
			delete[] arr;
		}
};

int main(){
	int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
	int size = sizeof(arr) / sizeof(arr[0]);
	MaxHeap heap(size);
	for(int i=0;i<size;i++){
		heap.insert(arr[i]);
	}
    cout << "Sorting Heap (in ascending order): ";
	heap.sort();
	return 0;
}
