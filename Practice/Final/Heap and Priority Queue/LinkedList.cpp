// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data=0){
            this->data = data;
            next = NULL;
        }
};

class PriorityQueue{
    private:
        Node *head;
    public:
        PriorityQueue(){
            head = NULL;
        }

        bool isEmpty(){
            if(head == NULL){
                return true;
            }else{
                return false;
            }
        }

        void print(){
            if(head != NULL){
                Node *temp = head;
                while(temp != NULL){
                    cout << temp->data << "  ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        void insert(int data){
            Node *n = new Node(data);
            if(head == NULL || data > head->data){
                n->next = head;
                head = n;
            }else{
                Node *temp = head;
                Node *prev = NULL;
                while(temp != NULL && data < temp->data){
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = n;
                n->next = temp;
            }
        }

        void pop(){
            if(!isEmpty()){
                if(head->next == NULL){
                    delete head;
                    head = NULL;
                }else{
                    Node *temp = head;
                    head = head->next;
                    delete temp;
                }
            }
        }

        int top(){
            if(isEmpty()){
                return -1;
            }else{
                return head->data;
            }
        }
};

int main(){
    PriorityQueue queue;
    queue.insert(10);
    queue.insert(20);
    queue.insert(15);
    queue.insert(50);
    queue.insert(30);
    queue.print();
    queue.pop();
    queue.print();
    return 0;
}