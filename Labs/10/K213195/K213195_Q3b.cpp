#include <iostream>
using namespace std;

class MinHeap{
	private:
		int capacity;
		int size;
		int *arr;
	public:
		MinHeap(int capacity){
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
			if(size == capacity){
				cout << "Head is full" << endl;
			}
			size++;
			int i = size - 1;
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

		int getIndex(int data){
			for(int i=0;i<size;i++){
				if(arr[i] == data){
					return i;
				}
			}
			return -1;
		}

		void decreaseKey(int i, int data){
			arr[i] = data;
			while(i != 0 && arr[i] < arr[parent(i)]){
				swap(arr[i], arr[parent(i)]);
				i = parent(i);
			}
		}

		int extractMin(){
			if(size == 0){
				cout << "Heap is empty" << endl;
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
			int smallest = i;
			if(left < size && arr[left] < arr[smallest]){
				smallest = left;
			}
			if(right < size && arr[right] < arr[smallest]){
				smallest = right;
			}
			if(smallest != i){
				swap(arr[i], arr[smallest]);
				heapify(smallest);
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

		~MinHeap(){
			delete[] arr;
		}
};

int main(){
	int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
	int size = sizeof(arr) / sizeof(arr[0]);
	MinHeap heap(size);
	for(int i=0;i<size;i++){
		heap.insert(arr[i]);
	}
	heap.printHeap();
	heap.deleteData(35);
	heap.printHeap();
	return 0;
}
