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

		bool isEmpty(){
			if(size == 0){
				return true;
			}else{
				return false;
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
				cout << "Heap is full" << endl;
				return;
			}
			size++;
			int i = size - 1;
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

		int top(){
			return arr[0];
		}
};

int nonIncreasingOrder(int arr[], int n){
	int sum = 0, dif = 0;
	MinHeap heap(n);
		
	for (int i = 0; i < n; i++) {
		if (!heap.isEmpty() && heap.top() < arr[i]) {
			dif = arr[i] - heap.top();
			sum += dif;
			heap.extractMin();
			heap.insert(arr[i]);
		}
		heap.insert(arr[i]);
	}
		
	return sum;
}

int main(){
	int arr[] = {3, 1, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum number of operations required: " << nonIncreasingOrder(arr, n) << endl;
    return 0;
}
