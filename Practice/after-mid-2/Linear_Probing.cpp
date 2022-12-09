// Sufiyaan Usmani

#include <iostream>
#define n 4
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
            table = new HashEntry*[n];
            for(int i=0;i<n;i++){
                table[i] = NULL;
            }
        }

        int hashFunction(int key){
            return(key % n);
        }

        int probe(int key){
            int i = 0;
            while(table[(hashFunction(key) + i) % n] != NULL){
                i++;
            }
            return((hashFunction(key) + i) % n);
        }

        void insert(int key, int data){
            HashEntry *e = new HashEntry(key, data);
            int hash = hashFunction(key);
            if(table[hash] != NULL){
                hash = probe(hash);
            }
            table[hash] = e;
        }

        void remove(int key){
            int hash = hashFunction(key);
            while(table[hash] != NULL && table[hash]->key != key){
                hash = hashFunction(hash + 1);
            }
            if(table[hash] == NULL){
                cout << "Not found" << endl;
            }else{
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
                cout << "Not found" << endl;
            }else{
                cout << "Found" << endl;
            }
        }

        ~HashTable(){
            for(int i=n-1;i>=0;i--){
                delete table[i];
            }
            delete[] table;
            table = NULL;
        }
};

int main(){
    HashTable table;
    table.insert(2, 10);
    table.insert(12, 20);
    table.remove(2);
    table.search(2);
    return 0;
}