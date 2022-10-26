#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int data = 0)
	{
		this->data = data;
		next = NULL;
	}
};

class LinkedList
{
private:
	Node *head;

public:
	LinkedList()
	{
		head = NULL;
	}

	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void printList()
	{
		if (isEmpty())
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node *temp = head;
			while (temp != NULL)
			{
				cout << "  " << temp->data << endl;
				temp = temp->next;
			}
			cout << endl;
		}
	}

	int getNodeCount()
	{
		int count = 0;
		Node *temp = head;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	int sum()
	{
		int total = 0;
		Node *temp = head;
		while (temp != NULL)
		{
			total += temp->data;
			temp = temp->next;
		}
		return total;
	}

	// Inserting at the front
	void pushFront(int data)
	{
		Node *newNode = new Node(data);
		newNode->next = head;
		head = newNode;
	}

	// Inserting after a given node
	void insertAfter(Node *previous, int data)
	{
		if (previous == NULL)
		{
			cout << "Previous Node can not be NULL" << endl;
		}
		else
		{
			Node *newNode = new Node(data);
			newNode->next = previous->next;
			previous->next = newNode;
		}
	}

	// Inserting at the end
	void pushBack(int data)
	{
		Node *newNode = new Node(data);
		if (head = NULL)
		{
			head = newNode;
		}
		else
		{
			Node *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	// delete first node
	void deleteFromHead()
	{
		if (isEmpty())
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}

	// deleting node based on value (first occurence)
	void deleteNode(int value)
	{
		if (isEmpty())
		{
			cout << "List is empty" << endl;
		}
		else
		{
			bool found = true;
			Node *temp = head;
			Node *before = NULL;
			if (head->data == value)
			{
				temp = head;
				head = head->next;
				delete temp;
			}
			else
			{
				while (temp->data != value)
				{
					before = temp;
					temp = temp->next;
					if (temp == NULL)
					{
						found = false;
						break;
					}
				}
				if (found == true)
				{
					before->next = temp->next;
					delete temp;
				}
				else
				{
					cout << "Not found" << endl;
				}
			}
		}
	}

	// delete from the last
	void deleteFromTail()
	{
		if (isEmpty())
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node *temp = head;
			// if only one node
			if (temp->next == NULL)
			{
				head = NULL;
				delete temp;
			}
			else
			{
				while (temp->next->next != NULL)
				{
					temp = temp->next;
				}
				Node *last = temp->next;
				temp->next = NULL;
				delete last;
			}
		}
	}

	// Delete List
	void deleteList()
	{
		if (isEmpty())
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node *t1, *t2;
			t1 = NULL;
			t2 = head;
			while (t2 != NULL)
			{
				t1 = t2;
				t2 = t2->next;
				delete t1;
			}
		}
	}

	void reverse()
	{
		Node *current = head;
		Node *next = NULL;
		Node *prev = NULL;

		while (current != NULL)
		{
			head = current;

			next = current->next;
			current->next = prev;

			prev = current;
			current = next;
		}
	}

	~LinkedList()
	{
		deleteList();
		head = NULL;
	}
};

int main()
{
	LinkedList sll;
	cout << "\nPush front 2 4 6\n";
	sll.pushFront(2);
	sll.pushFront(4);
	sll.pushFront(6);
	sll.printList();
	return 0;
}