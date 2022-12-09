// Sufiyaan Usmani

#include <iostream>
#define SIZE 5
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
            table = new HashEntry*[SIZE];
            for(int i=0;i<SIZE;i++){
                table[i] = NULL;
            }
        }

        int hashFunction(int key){
            return(key % SIZE);
        }

        void insert(int key, int data){
            HashEntry *e = new HashEntry(key, data);
            int hash = hashFunction(key);
            if(table[hash] != NULL){
                delete table[hash];
            }
            table[hash] = e;
        }

        void remove(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL || table[hash]->key != key){
                cout << "Not found" << endl;
                return;
            }
            delete table[hash];
            table[hash] = NULL;
        }

        void search(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL || table[hash]->key != key){
                cout << "Not found" << endl;
            }else{
                cout << "Found" << endl;
            }
        }

        void printTable(){
            for(int i=0;i<SIZE;i++){
                if(table[i] == NULL){
                    cout << i << ". EMPTY" << endl;
                }else{
                    cout << i << ". " << table[i]->key << " -> " << table[i]->data << endl;
                }
            }
            cout << endl;
        }

        ~HashTable(){
            for(int i=SIZE-1;i>=0;i--){
                delete table[i];
            }
            delete[] table;
            table = NULL;
        }
};

int main(){
    HashTable t;
    t.insert(9, 10);
    t.insert(2, 20);
    t.insert(6, 30);
    t.insert(90, 40);
    t.printTable();
    t.remove(6);
    t.printTable();
    return 0;
}