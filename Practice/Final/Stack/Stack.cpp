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

class Stack{
    private:
        Node *top;
    public:
        Stack(){
            top = NULL;
        }

        bool isEmpty(){
            if(top == NULL){
                return true;
            }else{
                return false;
            }
        }

        void display(){
            if(isEmpty()){
                cout << "Empty" << endl;
            }else{
                Node *temp = top;
                while(temp != NULL){
                    cout << temp->data << endl;
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        void push(int data){
            Node *n = new Node(data);
            n->next = top;
            top = n;
        }

        void pop(){
            if(!isEmpty()){
                Node *temp = top;
                top = top->next;
                delete temp;
            }
        }

        int getTop(){
            if(isEmpty()){
                return -1;
            }else{
                return top->data;
            }
        }

        int count(){
            int total = 0;
            Node *temp = top;
            while(temp != NULL){
                temp = temp->next;
                total++;
            }
            return total;
        }
};

int main(){
    Stack stack;
    cout << stack.count() << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    cout << stack.getTop() << endl;
    stack.pop();
    cout << "----" << endl;
    stack.display();
    return 0;
}