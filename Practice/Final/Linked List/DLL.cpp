// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int data){
            this->data = data;
            prev = next = NULL;
        }
};

class DoublyLinkedList{
    private:
        Node *head;
        Node *tail;
    public:
        DoublyLinkedList(){
            head = tail = NULL;
        }

        bool isEmpty(){
            if(head == NULL && tail == NULL){
                return true;
            }else{
                return false;
            }
        }

        void print(){
            if(!isEmpty()){
                Node *temp = head;
                while(temp != NULL){
                    cout << temp->data << " <-> ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        void prepend(int data){
            Node *n = new Node(data);
            if(isEmpty()){
                head = tail = n;
            }else{
                n->next = head;
                head->prev = n;
                head = n;
            }
        }

        void append(int data){
            Node *n = new Node(data);
            if(isEmpty()){
                head = tail = n;
            }else{
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
        }

        void insert(int index, int data){
            Node *n = new Node(data);
            if(index == 0){
                prepend(data);
            }else{
                Node *temp = head;
                Node *prev = NULL;
                int i = 0;
                while(temp != NULL && i != index){
                    prev = temp;
                    temp = temp->next;
                    i++;
                }
                if(temp != NULL){
                    prev->next = n;
                    n->prev = prev;
                    n->next = temp;
                    temp->prev = n;
                }else{
                    append(data);
                }
            }
        }

        void deleteFirstNode(){
            if(isEmpty()){
                cout << "Empty" << endl;
            }else{
                if(head == tail){
                    delete head;
                    head = tail = NULL;
                }else{
                    Node *temp = head;
                    head = head->next;
                    head->prev = NULL;
                    delete temp;
                }
            }
        }

        void deleteLastNode(){
            if(isEmpty()){
                cout << "Empty" << endl;
            }else{
                if(head == tail){
                    delete head;
                    head = tail = NULL;
                }else{
                    Node *temp = tail;
                    tail = tail->prev;
                    tail->next = NULL;
                    delete temp;
                }
            }
        }

        void deleteNode(int index){
            if(isEmpty()){
                cout << "Empty" << endl;
            }else{
                if(index == 0){
                    deleteFirstNode();
                }else{
                    Node *temp = head;
                    Node *prev = NULL;
                    int i = 0;
                    while(temp != NULL && i != index){
                        prev = temp;
                        temp = temp->next;
                        i++;
                    }
                    if(temp != NULL){
                        prev->next = temp->next;
                        temp->next->prev = prev;
                        delete temp;
                    }else{
                        cout << "Invalid index" << endl;
                    }
                }
            }
        }
};

int main(){
    DoublyLinkedList dll;
    dll.append(20);
    dll.prepend(10);
    dll.insert(2, 30);
    dll.print();
    dll.deleteNode(1);
    dll.print();
    return 0;
}