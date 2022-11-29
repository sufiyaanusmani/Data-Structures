// Sufiyaan Usmani

#include <iostream>
#define SIZE 1000
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
            long int x = key * key;;
				
            if(x > 99 && x < 1000){
			    return (x / 10) % 10;
			}else if(x > 999 && x < 100000){
				return  (x / 10) % 100;
			}else if(x > 9999 && x < 100000){
				return (x / 10) % 1000;
		    }
        }

        void insert(int key, int data){
            HashEntry *entry = new HashEntry(key, data);
            int hash =  hashFunction(key);
            if(table[hash] != NULL){
                delete table[hash];
            }
            table[hash] = entry;
            cout << data << " inserted successfully at index: " << hash << endl;
        }

        void remove(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL || table[hash]->key != key){
                cout << "Key not found" << endl;
            }else{
                cout << table[hash]->data << " deleted successfully" << endl;
                delete table[hash];
                table[hash] = NULL;
            }
        }

        void search(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL || table[hash]->key != key){
                cout << "Key not found" << endl;
            }else{
                cout << "Key: " << table[hash]->key << ", Data: " << table[hash]->data << endl;
            }
        }

        ~HashTable(){
            for(int i=0;i<SIZE;i++){
                if(table[i] != NULL){
                    delete table[i];
                    table[i] = NULL;
                }
            }
            delete[] table;
            table = NULL;
        }
};

int main(){
    HashTable table;
    table.insert(11, 21);
    table.insert(22, 12);
    table.insert(42, 88);
    table.search(22);
    table.search(42);
    table.remove(11);
    table.search(11);
    return 0;
}