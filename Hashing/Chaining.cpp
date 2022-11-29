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
                cout << data << " inserted at index: " << hash << endl;
            }else{
                Entry *temp = table[hash];
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = e;
                cout << data << " inserted at index: " << hash << endl;
            }
        }

        void remove(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL){
                cout << "Key not found" << endl;
            }else{
                if(table[hash]->key == key){
                    Entry *temp = table[hash];
                    table[hash] = table[hash]->next;
                    delete temp;
                }else{
                    Entry *temp = table[hash];
                    Entry *prev = NULL;
                    while(temp != NULL && temp->key != key){
                        prev = temp;
                        temp = temp->next;
                    }
                    if(temp == NULL){
                        cout << "Key not found" << endl;
                    }else{
                        cout << temp->data << " deleted from index: " << hash << endl;
                        prev->next = temp->next;
                        delete temp;
                    }
                }
            }
        }

        void search(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL){
                cout << "Key not found" << endl;
            }else{
                Entry *temp = table[hash];
                while(temp != NULL && temp->key != key){
                    temp = temp->next;
                }
                if(temp == NULL){
                    cout << "Key not found" << endl;
                }else{
                    cout << "Key: " << temp->key << ", Data: " << temp->data << endl;
                }
            }
        }
};

int main(){
    HashTable table;
    table.insert(2, 10);
    table.insert(12, 20);
    table.remove(2);
    table.search(12);
    return 0;
}