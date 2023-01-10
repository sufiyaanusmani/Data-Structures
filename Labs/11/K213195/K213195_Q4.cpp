// Sufiyaan Usmani

#include <iostream>
#define SIZE 20
using namespace std;

class Contact{
    public:
        int ID;
        string contactNumber;
        Contact *next;

        Contact(int ID, string contactNumber){
            this->ID = ID;
            this->contactNumber = contactNumber;
            next = NULL;
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

        void insert(int ID, string contactNumber){
            Contact *c = new Contact(ID, contactNumber);
            int hash = hashFunction(ID);
            if(book[hash] == NULL){
                book[hash] = c;
            }else{
                Contact *temp = book[hash];
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = c;
            }
            cout << "Contact added successfully at index: " << hash << endl;
        }

        void remove(int ID){
            int hash = hashFunction(ID);
            if(book[hash] == NULL){
                cout << "Contact not found" << endl;
            }else{
                if(book[hash]->ID == ID){
                    Contact *temp = book[hash];
                    Contact *next = book[hash]->next;
                    delete temp;
                    book[hash] = next;
                    cout << "Contact deleted successfully" << endl;
                }else{
                    Contact *temp = book[hash];
                    Contact *prev = NULL;
                    while(temp != NULL){
                        if(temp->ID == ID){
                            break;
                        }
                        prev = temp;
                        temp = temp->next;
                    }
                    if(temp == NULL){
                        cout << "Contact not found" << endl;
                    }else{
                        prev->next = temp->next;
                        delete temp;
                        cout << "Contact deleted successfully" << endl;
                    }
                }
            }
        }

        void search(int ID){
            int hash = hashFunction(ID);
            if(book[hash] == NULL){
                cout << "Not found" << endl;
                return;
            }else{
                Contact *temp = book[hash];
                while(temp != NULL){
                    if(temp->ID == ID){
                        cout << "ID: " << ID << endl;
                        cout << "Contact Number: " << temp->contactNumber << endl;
                        return;
                    }
                    temp = temp->next;
                }
            }
            cout << "Data not found" << endl;
        }
};

int main(){
    ContactBook book;
    book.insert(23, "03054354");
    book.insert(33, "03034522");
    book.insert(43, "03076666");
    book.remove(33);
    book.search(43);
    return 0;
}