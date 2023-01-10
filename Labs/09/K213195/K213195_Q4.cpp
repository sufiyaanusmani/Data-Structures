// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 4

#include <iostream>
using namespace std;

class Queue{
    private:
        int front, rear, size, capacity;
        int *arr;

    public:
        Queue(int capacity=0){
            this->capacity = capacity;
            arr = new int[this->capacity];
            front = rear = -1;
            size = 0;
        }

        bool isEmpty(){
            if(front == -1 && rear == -1 && size == 0){
                return true;
            }else{
                return false;
            }
        }

        bool isFull(){
            if(rear == capacity - 1){
                return true;
            }else{
                return false;
            }
        }

        void addMember(int data){
            if(isFull()){
                cout << "Queue is full" << endl;
            }else{
                if(isEmpty()){
                    front = rear = 0;
                }else{
                    rear++;
                }
                arr[rear] = data;
                size++;
            }
        }

        void removeMember(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
            }else{
                arr[front] = 0;
                if(front == rear){
                    front = rear = -1;
                }else{
                    front++;
                }
                size--;
            }
        }

        int queueCapacity(){
            if(rear == capacity - 1){
                cout << "Queue is full" << endl;
            }
        }

        void print(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
            }else{
                for(int i=front;i<=rear;i++){
                    cout << arr[i] << "  ";
                }
                cout << endl;
            }
        }
};

int main(){
    int n;
    cout << "Enter size of queue: ";
    cin >> n;
    Queue queue(n);
    while(1){
        cout << "\nQueue: ";
        queue.print();
        cout << "\n1. Add Member" << endl;
        cout << "2. Remove Member" << endl;
        cout << "3. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> n;
        
        if(n == 1){
            cout << "Enter data to add: ";
            cin >> n;
            queue.addMember(n);
        }else if(n == 2){
            queue.removeMember();
        }else if(n == 3){
            break;
        }else{
            cout << "Wrong choice entered" << endl;
        }
    }
    return 0;
}