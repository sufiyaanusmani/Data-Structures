// Sufiyaan Usmani

#include <iostream>
#define TABLE_SIZE 128
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

        int hashFunction(int key){
            return(key % TABLE_SIZE);
        }

        void insert(int key, int data){
            int hash = hashFunction(key);
            while(table[hash] != NULL && table[hash]->key != key){
                hash = hashFunction(hash + 1);
            }
            if(table[hash] != NULL){
                delete table[hash];
            }
            table[hash] = new HashEntry(key, data);
            cout << data << " inserted at key: " << hash << endl;
        }

        int search(int key){
            int hash = hashFunction(key);
            while(table[hash] != NULL && table[hash]->key != key){
                hash = hashFunction(hash + 1);
            }

            if(table[hash] == NULL){
                return -1;
            }else{
                return table[hash]->data;
            }
        }

        void remove(int key){
            int hash = hashFunction(key);
            while(table[hash] != NULL){
                if(table[hash]->key == key){
                    break;
                }
                hash = hashFunction(hash + 1);
            }
            if(table[hash] == NULL){
                cout << "Element not found" << endl;
            }else{
                delete table[hash];
                table[hash] = NULL;
                cout << "Element Deleted from key: " << hash << endl;
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
    table.insert(5, 30);
    table.insert(5, 40);
    table.remove(130);
    table.remove(5);
    return 0;
}