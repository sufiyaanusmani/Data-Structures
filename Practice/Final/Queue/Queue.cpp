// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
    
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class Queue{
    private:
        Node *front;
        Node *rear;
    public:
        Queue(){
            front = rear = NULL;
        }

        bool isEmpty(){
            if(front == NULL && rear == NULL){
                return true;
            }else{
                return false;
            }
        }

        void enqueue(int data){
            Node *n = new Node(data);
            if(isEmpty()){
                front = rear = n;
            }else{
                rear->next = n;
                rear = n;
            }
        }

        void dequeue(){
            if(!isEmpty()){
                if(front == rear){
                    delete front;
                    front = rear = NULL;
                }else{
                    Node *temp = front;
                    front = front->next;
                    delete temp;
                }
            }
        }

        void display(){
            if(isEmpty()){
                cout << "empty" << endl;
            }else{
                Node *temp = front;
                while(temp != NULL){
                    cout << temp->data << "  ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
};

int main(){
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    queue.dequeue();
    queue.dequeue();
    queue.display();
    return 0;
}