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

        int multiplicationHash(int v){
            return	floor (TABLE_SIZE * fmod((v * 0.618033), 1));
        }

        void insert(int key, int data){
            int hash = multiplicationHash(key);
            if(table[hash] != NULL){
                delete table[hash];
            }
            table[hash] = new HashEntry(key, data);
            cout << "Element inserted at table index: " << hash << endl;
        }

        int search(int key){
            int index = multiplicationHash(key);
            if(table[index] == NULL){
                return -1;
            }else{
                return table[index]->data;
            }
        }

        void remove(int key){
            int index = multiplicationHash(key);
            if(table[index] == NULL){
                cout << "Element not found" << endl;
            }else{
                cout << "Element deleted from table index: " << index << endl;
                delete table[index];
                table[index] = NULL;
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
    table.insert(150, 90);
    table.insert(5, 40);
    table.remove(360);
    table.insert(6, 99);
    return 0;
}