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

class SinglyLinkedList{
    public:
        Node *head;
    
        SinglyLinkedList(){
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
            if(head == NULL){
                cout << "Empty" << endl;
            }else{
                Node *temp = head;
                while(temp != NULL){
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        int count(){
            int i = 0;
            Node *temp = head;
            while(temp != NULL){
                temp = temp->next;
                i++;
            }
            return i;
        }

        void prepend(int data){
            Node *n = new Node(data);
            n->next = head;
            head = n;
        }

        void append(int data){
            Node *n = new Node(data);
            if(head == NULL){
                head = n;
            }else{
                Node *temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = n;
            }
        }

        void insertAfter(int index, int data){
            if(index <= count()){
                Node *n = new Node(data);
                if(index == 0){
                    head = n;
                }else{
                    int i;
                    Node *temp = head;
                    Node *prev = NULL;
                    while(temp != NULL && i != index){
                        prev = temp;
                        temp = temp->next;
                    }
                    prev->next = n;
                    n->next = temp;
                }
            }else{
                cout << "Invalid index" << endl;
            }
        }

        void deleteFirstNode(){
            if(head == NULL){
                cout << "List is empty" << endl;
            }else{
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }

        void deleteLastNode(){
            if(head == NULL){
                cout << "List is empty" << endl;
            }else{
                Node *temp = head;
                Node *prev = NULL;
                while(temp->next != NULL){
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = NULL;
                delete temp;
            }
        }

        void deleteNode(int index){
            if(index < count()){
                if(index == 0){
                    deleteFirstNode();
                }else if(index == count() - 1){
                    deleteLastNode();
                }else{
                    Node *temp = head;
                    Node *prev = NULL;
                    int i = 0;
                    while(temp != NULL && i != index){
                        prev = temp;
                        temp = temp->next;
                        i++;
                    }
                    prev->next = temp->next;
                    delete temp;
                }
            }else{
                cout << "Invalid index" << endl;
            }
        }
};

int main(){
    SinglyLinkedList sll;
    sll.append(10);
    sll.prepend(20);
    sll.prepend(30);
    sll.print();
    sll.deleteNode(1);
    sll.print();
    return 0;
}