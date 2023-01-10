#include <iostream>
using namespace std;

class Heap{
	private:
		int capacity;
		int size;
		int *arr;
	public:
		Heap(int capacity){
			this->capacity = capacity;
			size = 0;
			arr = new int[capacity];
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

		void buildHeap(int a[], int n){
			for(int i=0;i<n;i++){
				insert(a[i]);
			}
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
			int l = leftChild(i);
			int r = rightChild(r);
			int smallest = i;
			
			if(l < size && arr[l] < arr[smallest]){
				smallest = l;
			}
			if(r < size && arr[r] < arr[smallest]){
				smallest = r;
			}
			if(i != smallest){
				swap(arr[i], arr[smallest]);
				heapify(smallest);
			}
		}

		void heapSort(int *arr, int n){
			for(int i=0;i<n;i++){
				arr[i] = extractMin();
			}
		}

		~Heap(){
			delete[] arr;
		}
};

int main(){
	int arr[] = {4, 1, 3, 9, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	Heap heap(n);
	heap.buildHeap(arr, n);
	cout << "Heap: " << endl;
	heap.printHeap();

	int *sortedArray = new int[n];
	heap.heapSort(sortedArray, n);
	cout << "\nSorted Array: ";
	for(int i=0;i<n;i++){
		cout << sortedArray[i] << "  ";
	}
	delete[] sortedArray;
	return 0;
}
