// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(int data=0){
			this->data = data;
			next = NULL;
		}
};

class LinkedList{
	public:
		Node *head;

		LinkedList(){
			head = NULL;
		}

		void append(int data){
			Node *n = new Node(data);
			if(head == NULL){
				head = n;
			}else{
				Node *temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = n;
			}
		}

		void deleteFirstNode(){
			if(head != NULL){
				Node *temp = head;
				head = head->next;
				delete temp;
			}
		}

		void deleteLastNode(){
			if(head != NULL){
				if(head->next == NULL){
					delete head;
					head = NULL;
				}else{
					Node *temp = head;
					Node *prev = NULL;
					while(temp->next != NULL){
						prev = temp;
						temp = temp->next;
					}
					prev->next = NULL;
					delete temp;
				}
			}
		}

		int count(){
			int total = 0;
			Node *temp = head;
			while(temp != NULL){
				temp = temp->next;
				total++;
			}
			return total;
		}

		void deleteNode(int index){
			if(index >= count()){
				return;
			}
			if(head != NULL){
				if(index == 0){
					deleteFirstNode();
				}else if(index == count() - 1){
					deleteLastNode();
				}else{
					int i = 0;
					Node *temp = head;
					Node *prev = NULL;
					while(i != index){
						prev = temp;
						temp = temp->next;
						i++;
					}
					prev->next = temp->next;
					delete temp;
				}
			}
		}

		void print(){
			Node *temp = head;
			while(temp != NULL){
				cout << temp->data << "  ";
				temp = temp->next;
			}
			cout << endl;
		}
};

void doDeletion(LinkedList &l1, LinkedList &l2){
	int count = l1.count();
	Node *temp1 = l1.head;
	Node *temp2 = l2.head;
	Node *prev = NULL;
	int i = 0;
	int index;
	while(temp2 != NULL){
		index = temp2->data;
		if(index < count){
			while(i!=index-1){
				prev = temp1;
				temp1 = temp1->next;
				i++;
			}
			if(temp1->next == NULL){
				prev->next = NULL;
				delete temp1;
			}else{
				Node *toDelete = temp1->next;
				temp1->next = toDelete->next;
				delete toDelete;
			}
		}
		temp2 = temp2->next;		
	}
}

int main(){
	LinkedList l1, l2;
	l1.append(1); // 0	
	l1.append(2); // 1	
	l1.append(3); // 2
	l1.append(4); // 3
	l1.append(5); // 4
	l2.append(2);
	l2.append(4); 
	l2.append(8);
	doDeletion(l1, l2);
	l1.print();	
	return 0;
}