// Sufiyaan Usmani

#include <iostream>
#define SIZE 10
using namespace std;

class Entry{
    public:
        int key;
        int data;
        Entry *next;

        Entry(int key, int data){
            this->key = key;
            this->data = data;
            next = NULL;
        }
};

class HashTable{
    private:
        Entry **table;
    public:
        HashTable(){
            table = new Entry*[SIZE];
            for(int i=0;i<SIZE;i++){
                table[i] = NULL;
            }
        }

        int hashFunction(int key){
            return(key % SIZE);
        }

        void insert(int key, int data){
            Entry *e = new Entry(key, data);
            int hash = hashFunction(key);
            if(table[hash] == NULL){
                table[hash] = e;
            }else{
                Entry *temp = table[hash];
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = e;
            }
        }

        void remove(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL){
                cout << "Not found" << endl;
            }else if(table[hash]->key == key){
                Entry *temp = table[hash];
                table[hash] = table[hash]->next;
                delete temp;
                cout << "Deleted" << endl;
            }else{
                Entry *temp = table[hash];
                Entry *prev = NULL;
                while(temp != NULL && temp->key != key){
                    prev = temp;
                    temp = temp->next;
                }
                if(temp == NULL){
                    cout << "Not found" << endl;
                }else{
                    prev->next = temp->next;
                    delete temp;
                    cout << "Deleted" << endl;
                }
            }
        }

        void print(){
            for(int i=0;i<SIZE;i++){
                cout << i << ": ";
                Entry *temp = table[i];
                if(temp == NULL){
                    cout << "NULL" << endl;
                }else{
                    while(temp != NULL){
                        cout << temp->data << ", ";
                        temp = temp->next;
                    }
                    cout << endl;
                }
            }
        }

        void search(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL){
                cout << "Not found 1" << endl;
            }else{
                Entry *temp = table[hash];
                while(temp != NULL && temp->key != key){
                    temp = temp->next;
                }
                if(temp == NULL){
                    cout << "Not found 2" << endl;
                }else{
                    cout << temp->data << endl;
                }
            }
        }
};

int main(){
    HashTable h;
    h.insert(3,21);
    h.insert(33,212);
    h.insert(99,255);
    h.insert(9,23);
    h.insert(75,65);
    h.search(33);
    cout << endl;
    h.print();
    cout << endl;
    h.remove(9);
    cout << endl;
    h.print();

    return 0;
}