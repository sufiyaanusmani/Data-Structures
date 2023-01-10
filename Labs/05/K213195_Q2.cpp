// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Task 2

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

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

class CircularLinkedList
{
private:
	Node *tail;

public:
	CircularLinkedList()
	{
		tail = NULL;
	}

	void printList()
	{
		if (tail == NULL)
		{
			cout << "Error: List is empty" << endl;
			Sleep(1000);
		}
		else
		{
			Node *temp = tail->next;
			do
			{
				cout << temp->data << "  ";
				temp = temp->next;
			} while (temp != tail->next);
			cout << endl;
			cout << "\nPress any key to continue...";
			getch();
		}
	}

	void append(int data)
	{
		Node *n = new Node(data);
		if (tail == NULL)
		{
			tail = n;
			tail->next = n;
		}
		else
		{
			n->next = tail->next;
			tail->next = n;
			tail = n;
		}
	}

	void prepend(int data)
	{
		Node *n = new Node(data);
		if (tail == NULL)
		{
			tail = n;
			tail->next = n;
		}
		else
		{
			n->next = tail->next;
			tail->next = n;
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
			Node *temp = tail->next;
			Node *prev = NULL;
			do
			{
				prev = temp;
				temp = temp->next;
				count++;
			} while (temp != tail->next && count != index);
			if (temp != tail->next)
			{
				prev->next = n;
				n->next = temp;
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
		if (tail == NULL)
		{
			cout << "Error: List is empty" << endl;
		}
		else
		{
			if (tail == tail->next)
			{
				// if only one node is present
				delete tail;
				tail = NULL;
			}
			else
			{
				Node *toDelete = tail->next;
				tail->next = toDelete->next;
				delete toDelete;
			}
		}
	}

	void deleteLastNode()
	{
		if (tail == NULL)
		{
			cout << "Error: List is empty" << endl;
		}
		else
		{
			if (tail == tail->next)
			{
				// if only one node present
				delete tail;
				tail = NULL;
			}
			else
			{
				Node *temp = tail->next;
				while (temp->next != tail)
				{
					temp = temp->next;
				}
				temp->next = tail->next;
				delete tail;
				tail = temp;
			}
		}
	}

	void deleteAtIndex(int index)
	{
		if (tail == NULL)
		{
			cout << "List is already empty" << endl;
		}
		else
		{
			if (index == 0)
			{
				deleteFirstNode();
			}
			else
			{
				Node *temp = tail->next;
				Node *prev = NULL;
				int count = 0;
				do
				{
					prev = temp;
					temp = temp->next;
					count++;
				} while (temp != tail->next && count != index);
				if (temp != tail->next)
				{
					if (temp == tail)
					{
						deleteLastNode();
					}
					else
					{
						prev->next = temp->next;
						delete temp;
					}
				}
				else
				{
					cout << "Error: Invalid Index" << endl;
				}
			}
		}
	}

	void updateNodeAtIndex(int index, int data)
	{
		if (tail == NULL)
		{
			cout << "List is empty" << endl;
			Sleep(1000);
		}
		else
		{
			if (index == 0)
			{
				tail->next->data = data;
			}
			else
			{
				Node *temp = tail->next;
				int count = 0;
				do
				{
					temp = temp->next;
					count++;
				} while (temp != tail->next && count != index);
				if (temp != tail->next)
				{
					temp->data = data;
				}
				else
				{
					cout << "Error: Invalid Index" << endl;
				}
			}
		}
	}

	// Destructor
	~CircularLinkedList()
	{
		if (tail != NULL)
		{
			Node *temp = tail->next;
			Node *prev = NULL;
			while (temp != tail)
			{
				prev = temp;
				temp = temp->next;
				delete prev;
			}
			delete tail;
		}
		tail = NULL;
	}
};

int main()
{
	int choice, index, data;

	CircularLinkedList cll;
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
			cll.append(data);
			break;
		case 2:
			cout << "Enter data: ";
			cin >> data;
			cll.prepend(data);
			break;
		case 3:
			cout << "Enter index: ";
			cin >> index;
			cout << "Enter data: ";
			cin >> data;
			cll.insertAtIndex(index, data);
			break;
		case 4:
			cll.deleteFirstNode();
			break;
		case 5:
			cll.deleteLastNode();
			break;
		case 6:
			cout << "Enter index: ";
			cin >> index;
			cll.deleteAtIndex(index);
			break;
		case 7:
			cout << "Enter index: ";
			cin >> index;
			cout << "Enter new data: ";
			cin >> data;
			cll.updateNodeAtIndex(index, data);
			break;
		case 8:
			cll.printList();
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
