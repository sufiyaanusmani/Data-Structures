// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 1

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node *previous;

	Node()
	{
		data = 0;
		next = previous = NULL;
	}

	Node(int data)
	{
		this->data = data;
		previous = next = NULL;
	}
};

class DoublyLinkedList
{
private:
	Node *head;
	Node *tail;

public:
	DoublyLinkedList()
	{
		head = NULL;
	}

	void printList()
	{
		if (head == NULL)
		{
			// checking if list is empty
			cout << "List is empty" << endl;
			Sleep(1000);
		}
		else
		{
			Node *temp = head;
			while (temp != NULL)
			{
				cout << temp->data << "  ";
				temp = temp->next;
			}
			cout << endl;
			cout << "\nPress any key to continue...";
			getch();
		}
	}

	void append(int data)
	{
		Node *n = new Node(data);
		if (head == NULL)
		{
			// checking if list is empty
			head = tail = n;
		}
		else
		{
			tail->next = n;
			n->previous = tail;
			tail = n;
		}
	}

	void prepend(int data)
	{
		Node *n = new Node(data);
		if (head == NULL)
		{
			// checking if list is empty
			head = tail = n;
		}
		else
		{
			n->next = head;
			head->previous = n;
			head = n;
		}
	}

	void insertAtIndex(int index, int data)
	{
		Node *n = new Node(data);
		if (index == 0)
		{
			prepend(data);
		}
		else
		{
			int count = 0;
			Node *temp = head;
			Node *prev = NULL;
			while (temp != NULL && count != index)
			{
				prev = temp;
				temp = temp->next;
				count++;
			}
			if (temp != NULL)
			{
				n->next = temp;
				n->previous = prev;

				prev->next = n;
				temp->previous = n;
			}
			else
			{
				cout << "Error: Invalid Index" << endl;
				Sleep(1000);
			}
		}
	}

	void deleteFirstNode()
	{
		if (head == NULL)
		{
			// checking if list is empty
			cout << "Error: List is already empty" << endl;
			Sleep(1000);
		}
		else
		{
			// if only one node
			if (head == tail)
			{
				delete head;
				head = tail = NULL;
			}
			else
			{
				Node *toDelete = head;
				head = head->next;
				head->previous = NULL;
				delete toDelete;
			}
		}
	}

	void deleteLastNode()
	{
		if (head == NULL)
		{
			// checking if list is empty
			cout << "Error: List is already empty" << endl;
		}
		else
		{
			// if only one node
			if (head == tail)
			{
				delete head;
				head = tail = NULL;
			}
			else
			{
				Node *toDelete = tail;
				tail = tail->previous;
				tail->next = NULL;
				delete toDelete;
			}
		}
	}

	void deleteAtIndex(int index)
	{
		if (head == NULL)
		{
			cout << "Error: List is empty" << endl;
		}
		else
		{
			if (index == 0)
			{
				deleteFirstNode();
			}
			else
			{
				int count = 0;
				Node *temp = head;
				Node *prev = NULL;
				while (temp != NULL && count != index)
				{
					prev = temp;
					temp = temp->next;
					count++;
				}
				if (temp != NULL)
				{
					if (temp == tail)
					{
						deleteLastNode();
					}
					else
					{
						prev->next = temp->next;
						temp->next->previous = prev;
						delete temp;
					}
				}
				else
				{
					cout << "Error: Invalid Index" << endl;
					Sleep(1000);
				}
			}
		}
	}

	void updateNodeAtIndex(int index, int data)
	{
		if (head == NULL)
		{
			cout << "Error: List is empty" << endl;
			Sleep(1000);
		}
		else
		{
			int count = 0;
			Node *temp = head;
			while (temp != NULL && count != index)
			{
				temp = temp->next;
				count++;
			}
			if (temp != NULL)
			{
				temp->data = data;
			}
			else
			{
				cout << "Error: Invalid Index" << endl;
				Sleep(1000);
			}
		}
	}

	// Destructor
	~DoublyLinkedList()
	{
		if (head != NULL)
		{
			Node *temp = head;
			while (temp != NULL)
			{
				head = temp;
				temp = temp->next;
				delete head;
			}
		}
		head = tail = NULL;
	}
};

int main()
{
	int choice, index, data;

	DoublyLinkedList dll;
	while (1)
	{
		system("cls");
		cout << "1. Insert at the end (append)" << endl;
		cout << "2. Insert at the beginning (prepend)" << endl;
		cout << "3. Insert at index" << endl;
		cout << "4. Delete first node" << endl;
		cout << "5. Delete last node" << endl;
		cout << "6. Delete node at index" << endl;
		cout << "7. Update node at index" << endl;
		cout << "8. Print List" << endl;
		cout << "9. Exit" << endl;
		cout << "\nEnter your choice: ";
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case 1:
			cout << "Enter data: ";
			cin >> data;
			dll.append(data);
			break;
		case 2:
			cout << "Enter data: ";
			cin >> data;
			dll.prepend(data);
			break;
		case 3:
			cout << "Enter index: ";
			cin >> index;
			cout << "Enter data: ";
			cin >> data;
			dll.insertAtIndex(index, data);
			break;
		case 4:
			dll.deleteFirstNode();
			break;
		case 5:
			dll.deleteLastNode();
			break;
		case 6:
			cout << "Enter index: ";
			cin >> index;
			dll.deleteAtIndex(index);
			break;
		case 7:
			cout << "Enter index: ";
			cin >> index;
			cout << "Enter new data: ";
			cin >> data;
			dll.updateNodeAtIndex(index, data);
			break;
		case 8:
			dll.printList();
			break;
		case 9:
			exit(0);
			break;
		default:
			cout << "Wrong choice entered. Please enter a valid choice" << endl;
			Sleep(1000);
			break;
		}
	}
	return 0;
}
