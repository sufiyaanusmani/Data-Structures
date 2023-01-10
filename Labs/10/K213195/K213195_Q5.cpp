#include <iostream>
using namespace std;

class PriorityQueue{
	private:
		int capacity;
		int size;
		int *arr;
	public:
		PriorityQueue(int capacity){
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

		void enqueue(int data){
			if(capacity == size){
				cout << "Queue is full" << endl;
				return;
			}
			size++;
			int i = size - 1;
			arr[i] = data;
			while(i != 0 && arr[i] > arr[parent(i)]){
				swap(arr[i], arr[parent(i)]);
				i = parent(i);
			}
			cout << "Enqueue: " << data << endl;
		}

		int dequeue(){
			if(size == 0){
				cout << "Queue is empty" << endl;
				return -1;
			}else if(size == 1){
				size--;
				cout << "Dequeue: " << arr[0] << endl;
				return arr[0];
			}else{
				int data = arr[0];
				arr[0] = arr[size - 1];
				size--;
				heapify(0);
				cout << "Dequeue: " << data << endl;
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

		~PriorityQueue(){
			delete[] arr;
		}
};

int main(){
	PriorityQueue queue(6);
	queue.enqueue(4);
	queue.enqueue(5);
	queue.enqueue(9);
	queue.enqueue(3);
	queue.enqueue(1);
	queue.enqueue(2);
	cout << endl;
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	return 0;
}
