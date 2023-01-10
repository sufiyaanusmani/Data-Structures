// Sufiyaan Usmani

#include <iostream>
#include <string>
#define SIZE 20
using namespace std;

class Contact{
    public:
        int ID;
        string contactNumber;

        Contact(int ID, string contactNumber){
            this->ID = ID;
            this->contactNumber = contactNumber;
        }
};

class ContactBook{
    private:
        Contact **book;
    public:
        ContactBook(){
            book = new Contact*[SIZE];
            for(int i=0;i<SIZE;i++){
                book[i] = NULL;
            }
        }

        bool isEmpty(){
            for(int i=0;i<SIZE;i++){
                if(book[i] != NULL){
                    return false;
                }
            }
            return true;
        }

        int getSize(){
            return SIZE;
        }

        int hashFunction(int i){
            return(i % SIZE);
        }

        int probe(int key){
            int i = 0;
            while(book[(hashFunction(key) + i) % SIZE] != NULL){
                i++;
            }
            return((hashFunction(key) + i) % SIZE);
        }

        void insert(int ID, string contactNumber){
            Contact *c = new Contact(ID, contactNumber);
            int hash = hashFunction(ID);
            if(book[hash] != NULL){
                hash = probe(hash);
            }
            book[hash] = c;
            cout << "Data inserted at index: " << hash << endl;
        }

        void search(int ID){
            int hash = hashFunction(ID);
            int i = 0;
            while((book[(hashFunction(ID) + i) % SIZE]->ID != ID) && (book[(hashFunction(ID) + i) % SIZE] != NULL)){
                i++;
            }
            if(book[(hashFunction(ID) + i) % SIZE] == NULL){
                cout << "Data not found" << endl;
            }else{
                cout << "ID: " << book[(hashFunction(ID) + i) % SIZE]->ID << endl;
                cout << "Contact Number: " << book[(hashFunction(ID) + i) % SIZE]->contactNumber << endl;
            }
        }

        void remove(int ID){
            int hash = hashFunction(ID);
            int i = 0;
            while((book[(hashFunction(ID) + i) % SIZE]->ID != ID) && (book[(hashFunction(ID) + i) % SIZE] != NULL)){
                i++;
            }
            if(book[(hashFunction(ID) + i) % SIZE] == NULL){
                cout << "Data not found" << endl;
            }else{
                delete book[(hashFunction(ID) + i) % SIZE];
                book[(hashFunction(ID) + i) % SIZE] = NULL;
                cout << "Deleted data at index: " << (hashFunction(ID) + i) % SIZE << endl;
            }
        }
};

int main(){
    ContactBook book;
    book.insert(3195, "03363778582");
    book.insert(15, "03312324234");
    book.remove(15);
    return 0;
}