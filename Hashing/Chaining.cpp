// Sufiyaan Usmani

#include <iostream>
#define TABLE_SIZE 128
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

class Hash{
    private:
        Node **table;
    public:
        Hash(){
            table = new Node*[TABLE_SIZE];
            for(int i=0;i<TABLE_SIZE;i++){
                table[i] = NULL;
            }
        }

        int hashFunc(int data){
            return(data % TABLE_SIZE);
        }

        void insert(int data){
            int hashValue = hashFunc(data);
            Node *n = new Node(data);
            Node *entry = table[hashValue];
            Node *prev = NULL;
            
            while(entry != NULL){
                prev = entry;
                entry = entry->next;
            }

            if(prev == NULL){
                table[hashValue] = n;
            }else{
                prev->next = n;
            }
        }

        void remove(int data){
            int hashValue = hashFunc(data);
            Node *entry = table[hashValue];
            Node *prev = NULL;

            if(entry == NULL){
                cout << "Element does not exists" << endl;
                return;
            }

            if(entry->data == data){
                Node *temp = entry;
                entry = entry->next;
                delete temp;
                table[hashValue] = entry;
            }else{
                while(entry != NULL){
                    prev = entry;
                    entry = entry->next;
                    if(entry->data == data){
                        break;
                    }
                }
                if(entry->data == data){
                    prev->next = entry->next;
                    delete entry;
                    cout << "Deleted" << endl;
                }else{
                    cout << "Element does not exists" << endl;
                }
            }
        }

        bool search(int data){
            int hashValue = hashFunc(data);
            Node *entry = table[hashValue];
            while(entry != NULL){
                if(entry->data == data){
                    cout << "Data found" << endl;
                    return true;
                }
                entry = entry->next;
            }
            cout << "Not found" << endl;
            return false;
        }

        void printTable(){
            Node *temp;
            for(int i=0;i<TABLE_SIZE;i++){
                cout << i << " -> ";
                temp = table[i];
                while(temp != NULL){
                    cout << temp->data << "  ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        ~Hash(){
            for(int i=0;i<TABLE_SIZE;i++){
                Node *temp = table[i];
                Node *prev = NULL;
                while(temp != NULL){
                    prev = temp;
                    temp = temp->next;
                    delete prev;
                }
            }
            delete[] table;
            table = NULL;
        }
};

int main(){
    Hash hash;
    cout << "Inserting" << endl;
    hash.insert(23);
    cout << "Inserting" << endl;
    hash.insert(34);
    cout << "Inserting" << endl;
    hash.insert(4);
    cout << "Inserting" << endl;
    hash.insert(132);
    cout << "Searching" << endl;
    hash.search(34);
    hash.printTable();
    cout << "Removing" << endl;
    hash.remove(4);
    hash.printTable();
    cout << "Searching" << endl;
    hash.search(4);
    return 0;
}