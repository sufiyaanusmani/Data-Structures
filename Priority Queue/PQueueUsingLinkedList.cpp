// Sufiyaan Usmani
// higher priority at the front
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        int priority;
        Node *next;

        Node(int data, int priority){
            this->data = data;
            this->priority = priority;
            next = NULL;
        }
};

class PriorityQueue{
    private:
        Node *front;
    public:
        PriorityQueue(){
            front = NULL;
        }

        bool isEmpty(){
            if(front == NULL){
                return true;
            }else{
                return false;
            }
        }

        void insert(int data, int priority){
            Node *n = new Node(data, priority);
            if(isEmpty() || n->priority >= front->priority){
                n->next = front;
                front = n;
            }else{
                Node *temp = front;
                Node *prev = NULL;
                while(temp != NULL && temp->priority >= n->priority){
                    prev = temp;
                    temp = temp->next;
                }
                n->next = temp;
                prev->next = n;
            }
        }

        void deleteN(){
            if(isEmpty()){
                return;
            }else{
                Node *temp = front;
                front = front->next;
                delete temp;
            }
        }

        int peek(){
            if(!isEmpty()){
                return front->data;
            }
        }

        void print(){
            if(!isEmpty()){
                Node *temp = front;
                while(temp != NULL){
                    cout << temp->data << "  ";
                    temp = temp->next;
                }
                cout << endl;
            }else{
                cout << "Empty" << endl;
            }
        }
};

int main(){
    PriorityQueue queue;
    queue.insert(10, 4);
    queue.insert(5, 2);
    queue.insert(80, 3);
    queue.insert(50, 1);
    queue.insert(30, 5);
    queue.print();
    queue.deleteN();
    queue.deleteN();
    queue.print();
    return 0;
}