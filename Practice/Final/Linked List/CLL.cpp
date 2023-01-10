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

class CircularLinkedList{
    private:
        Node *tail;
    public:
        CircularLinkedList(){
            tail = NULL;
        }

        bool isEmpty(){
            if(tail == NULL){
                return true;
            }else{
                return false;
            }
        }

        void print(){
            if(isEmpty()){
                cout << "Empty" << endl;
            }else{
                Node *temp = tail->next;
                do{
                    cout << temp->data << "  ";
                    temp = temp->next;
                }while(temp != tail->next);
                cout << endl;
            }
        }

        void prepend(int data){
            Node *n = new Node(data);
            if(isEmpty()){
                tail = n;
                tail->next = n;
            }else{
                n->next = tail->next;
                tail->next = n;
            }
        }

        void append(int data){
            Node *n = new Node(data);
            if(isEmpty()){
                tail = n;
                tail->next = n;
            }else{
                n->next = tail->next;
                tail->next = n;
                tail = n;
            }
        }

        void deleteFirstNode(){
            if(isEmpty()){
                cout << "List is empty" << endl;
            }else{
                if(tail->next == tail){
                    delete tail;
                    tail = NULL;
                }else{
                    Node *temp = tail->next;
                    tail->next = temp->next;
                    delete temp;
                }
            }
        }

        void deleteLastNode(){
            if(isEmpty()){
                cout << "empty" << endl;
            }else{
                Node *temp = tail->next;
                do{
                    temp = temp->next;
                }while(temp->next != tail);
                temp->next = tail->next;
                delete tail;
                tail = temp;
            }
        }
};

int main(){
    CircularLinkedList cll;
    cll.append(1);
    cll.append(2);
    cll.append(3);
    cll.prepend(4);
    cll.print();
    cll.deleteFirstNode();
    cll.print();
    cll.deleteLastNode();
    cll.print();
    return 0;
}