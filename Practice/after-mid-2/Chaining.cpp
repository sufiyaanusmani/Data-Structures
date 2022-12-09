// Sufiyaan Usmani

#include <iostream>
#define n 5
using namespace std;

class HashEntry{
    public:
        int key;
        int data;
        HashEntry *next;

        HashEntry(int key, int data){
            this->key = key;
            this->data = data;
            next = NULL;
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

        void insert(int key, int data){
            HashEntry *e = new HashEntry(key, data);
            int hash = hashFunction(key);
            if(table[hash] == NULL){
                table[hash] = e;

            }else{
                HashEntry *temp = table[hash];
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = e;
            }
        }

        void remove(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL){
                cout << "Not found" << endl;;
            }else{
                HashEntry *temp = table[hash];
                HashEntry *prev = NULL;
                while(temp != NULL && table[hash]->key != key){
                    prev = temp;
                    temp = temp->next;
                }
                if(table[hash] == NULL){
                    cout << "Not found" << endl;
                    prev->next = temp->next;
                    delete temp;
                }
            }
        }
};

int main(){
    
    return 0;
}