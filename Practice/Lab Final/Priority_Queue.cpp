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

        void extract(){
            if(head == NULL){
                return;
            }
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        int top(){
            if(head == NULL){
                return -1;
            }
            return head->data;
        }
};

int main(){
    PriorityQueue queue;
    queue.insert(12);
    queue.insert(32);
    queue.insert(44);
    queue.insert(35);
    queue.insert(1);
    queue.insert(22);

    while(!queue.isEmpty()){
        cout << queue.top() << endl;
        queue.extract();
    }
    return 0;
}