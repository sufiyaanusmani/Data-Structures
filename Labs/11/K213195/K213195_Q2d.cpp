// Sufiyaan Usmani

#include <iostream>
#include <cmath>
#define TABLE_SIZE 1000
using namespace std;

class HashEntry{
    public:
        int key;
        int data;

        HashEntry(int key, int data){
            this->key = key;
            this->data = data;
        }
};

class HashTable{
    private:
        HashEntry **table;
    public:
        HashTable(){
            table = new HashEntry*[TABLE_SIZE];
            for(int i=0;i<TABLE_SIZE;i++){
                table[i] = NULL;
            }
        }

        int foldingHash(int key){
            return(key % 300);
        }

        void insert(int key, int data){
            int hash = foldingHash(key);
            if(table[hash] != NULL){
                delete table[hash];
            }
            table[hash] = new HashEntry(key, data);
            cout << data << " inserted at table index: " << hash << endl;
        }

        int search(int key){
            int hash = foldingHash(key);
            if(table[hash] == NULL || table[hash]->key != key){
                cout << "Not found" << endl;
                return -1;
            }else{
                cout << "Data: " << table[hash]->data << endl;
                return table[hash]->data;
            }
        }

        void remove(int key){
            int hash = foldingHash(key);
            if(table[hash] == NULL || table[hash]->key != key){
                cout << "Element not found" << endl;
            }else{
                cout << "Element deleted from table index: " << hash << endl;
                delete table[hash];
                table[hash] = NULL;
            }
        }

        ~HashTable(){
            for(int i=0;i<TABLE_SIZE;i++){
                delete table[i];
            }
            delete[] table;
            table = NULL;
        }
};

int main(){
    HashTable table;
    table.insert(2, 20);
    table.insert(130, 30);
    table.insert(450, 90);
    table.insert(5, 40);
    table.remove(36);
    table.insert(130, 99);
    table.remove(450);
    return 0;
}