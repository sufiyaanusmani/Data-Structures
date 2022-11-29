// Sufiyaan Usmani

#include <iostream>
#define SIZE 10
using namespace std;

class Entry{
    public:
        int key;
        int data;

        Entry(int key, int data){
            this->key = key;
            this->data = data;
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

        int probe(int hash){
            int i = 0;
            while(table[(hashFunction(hash) + i) % SIZE] != NULL){
                i++;
            }
            return ((hashFunction(hash) + i) % SIZE);
        }

        void insert(int key, int data){
            Entry *e = new Entry(key, data);
            int hash = hashFunction(key);
            if(table[hash] != NULL){
                hash = probe(hash);
            }
            table[hash] = e;
            cout << data << " inserted at index: " << hash << endl;
        }

        void remove(int key){
            int hash = hashFunction(key);
            while(table[hash] != NULL && table[hash]->key != key){
                hash = hashFunction(hash + 1);
            }
            if(table[hash] == NULL){
                cout << "Key not found" << endl;
            }else{
                cout << table[hash]->data << " deleted from index: " << hash << endl;
                delete table[hash];
                table[hash] = NULL;
            }
        }

        void search(int key){
            int hash = hashFunction(key);
            while(table[hash] != NULL && table[hash]->key != key){
                hash = hashFunction(hash + 1);
            }
            if(table[hash] == NULL){
                cout << "Key not found" << endl;
            }else{
                cout << "Key: " << table[hash]->key << ", Data: " << table[hash]->data << endl;
            }
        }
};

int main(){
    HashTable table;
    table.insert(2, 10);
    table.insert(12, 20);
    table.search(12);
    table.remove(2);
    return 0;
}