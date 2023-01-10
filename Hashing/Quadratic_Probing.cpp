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
			return key%SIZE;
		}

		void insert(int key, int data){
			int hash = hashFunction(key);
			Entry *e = new Entry(key, data);
			if(table[hash] == NULL){
				table[hash] = e;
				cout << "Inserted at index: " << hash << endl;
			}else{
				int newHash;
				for(int i=0;i<SIZE;i++){
					newHash = (hash + (i * i)) % SIZE;
					if(table[newHash] == NULL){
						table[newHash] = e;
						cout << "Inserted at index: " << newHash << endl;
						break;
					}
				}
			}
		}

		void search(int key){
			int hash = hashFunction(key);
			if(table[hash]->key == key){
				cout << "Found, Data: " << table[hash]->data << endl;
			}else{
				int newHash;
				for(int i=0;i<SIZE;i++){
					newHash = (hash + (i * i)) % SIZE;
					if(table[newHash] == NULL){
						cout << "Not found" << endl;
						break;
					}else if(table[newHash]->key == key){
						cout << "Found, Data: " << table[newHash]->data << " at index: " << newHash << endl;
						break;
					}
				}
			}
		}

		
};

int main(){
	HashTable table;
	table.insert(2, 100);
	table.insert(12, 20);
	table.insert(22, 30);
	table.search(22);
	return 0;
}