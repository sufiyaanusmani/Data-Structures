// Sufiyaan Usmani

#include <iostream>
#define DELETED -99999

using namespace std;

class Entry{
    public:
        int key;
        int data;

        Entry(){

        }

        Entry(int key, int data){
            this->key = key;
            this->data = data;
        }
};

class HashTable{
    private:
        int size;
        Entry **table;
        Entry deleted;
    public:
        HashTable(int size){
            this->size = size;
            table = new Entry*[size];
            for(int i=0;i<size;i++){
                table[i] = NULL;
            }
            deleted.key = DELETED;
            deleted.data = DELETED;
        }

        int hashFunction(int key){
            return(key % size);
        }

        void insert(int key, int data){
            Entry *e = new Entry(key, data);
            int hash = hashFunction(key);
            if(table[hash] == NULL || table[hash]->key == DELETED){
                table[hash] = e;
            }else{
                int newHash;
                for(int i=0;i<size;i++){
                    newHash = (hash + i) % size;
                    if(table[newHash] == NULL || table[newHash]->key == DELETED){
                        table[newHash] = e;
                        return;
                    }
                }
            }
        }

        void deleteData(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL){
                cout << "Not found" << endl;
            }else if(table[hash]->key == key){
                delete table[hash];
                table[hash] = &deleted;
            }else{
                int newHash;
                for(int i=0;i<size;i++){
                    newHash = (hash + i) % size;
                    if(table[newHash] == NULL){
                        cout << "Not found" << endl;
                        return;
                    }else if(table[newHash]->key == key){
                        delete table[newHash];
                        table[newHash] = &deleted;
                        return;
                    }
                }
            }
        }

        void search(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL){
                cout << "not found" << endl;
            }else if(table[hash]->key == key){
                cout << "found" << endl;
            }else{
                int newHash;
                for(int i=0;i<size;i++){
                    newHash = (hash + i) % size;
                    if(table[newHash] == NULL){
                        cout << "not found" << endl;
                        return;
                    }else if(table[newHash]->key == key){
                        cout << "Found" <<endl;
                        return;
                    }
                }
            }
        }

        void print(){
            for(int i=0;i<size;i++){
                cout << i << ": ";
                if(table[i]==NULL){
                    cout << "NULL" << endl;
                }else if(table[i] == &deleted){
                    cout << "DELETED" << endl;
                }else{
                    cout << "(" << table[i]->key << ", " << table[i]->data << ")" << endl;
                }
            }
        }
};

int main(){
    HashTable table(10);
    table.insert(5, 1);
    table.insert(15, 2);
    table.insert(25, 3);
    table.insert(35, 4);
    table.insert(45, 5);
    table.insert(55, 6);
    table.deleteData(25);
    table.insert(65, 7);
    table.print();
    return 0;
}