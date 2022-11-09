#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
	int data;
	Node *left, *right;
	Node(int data = 0)
	{
		this->data = data;
		left = right = NULL;
	}
};

class BST
{
public:
	Node *root;

	BST()
	{
		root = NULL;
	}

	bool isEmpty()
	{
		if (root == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void preorder(Node *r)
	{
		if (r == NULL)
		{
			return;
		}
		cout << r->data << "  ";
		preorder(r->left);
		preorder(r->right);
	}

	void inorder(Node *r)
	{
		if (r == NULL)
		{
			return;
		}
		inorder(r->left);
		cout << r->data << "  ";
		inorder(r->right);
	}

	void postorder(Node *r)
	{
		if (r == NULL)
		{
			return;
		}
		postorder(r->left);
		postorder(r->right);
		cout << r->data << "  ";
	}

	void insert(int data)
	{
		Node *n = new Node(data);
		if (root == NULL)
		{
			root = n;
		}
		else
		{
			Node *temp = root;
			while (temp != NULL)
			{
				if ((data < temp->data) && (temp->left == NULL))
				{
					temp->left = n;
					break;
				}
				else if (data < temp->data)
				{
					temp = temp->left;
				}
				else if ((data > temp->data) && (temp->right == NULL))
				{
					temp->right = n;
					break;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}

	Node *search(int data)
	{
		if (root == NULL)
		{
			cout << "Tree is empty" << endl;
			return NULL;
		}
		else
		{
			Node *temp = root;
			while (temp != NULL)
			{
				if (temp->data == data)
				{
					cout << "Data found" << endl;
					return temp;
				}
				else if (data < temp->data)
				{
					temp = temp->left;
				}
				else
				{
					temp = temp->right;
				}
			}
			cout << "Data not found" << endl;
			return NULL;
		}
	}

	int height(Node *r)
	{
		if (r == NULL)
		{
			return -1;
		}
		else
		{
			int hLeft = height(r->left);
			int hRight = height(r->right);
			if (hLeft > hRight)
			{
				return hLeft + 1;
			}
			else
			{
				return hRight + 1;
			}
		}
	}

	int count(Node *r)
	{
		if (r == NULL)
		{
			return 0;
		}
		else
		{
			int lCount = count(r->left);
			int rCount = count(r->right);
			return (lCount + rCount + 1);
		}
	}

	Node *getMin(Node *r)
	{
		if (r == NULL)
		{
			return NULL;
		}
		else
		{
			Node *temp = r;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			return temp;
		}
	}

	Node *getMax(Node *r)
	{
		if (r == NULL)
		{
			return NULL;
		}
		else
		{
			Node *temp = r;
			while (temp->right != NULL)
			{
				temp = temp->right;
			}
			return temp;
		}
	}

	Node *deleteNode(Node *r, int data)
	{
		if (r == NULL)
		{
			return NULL;
		}
		else if (data < r->data)
		{
			r->left = deleteNode(r->left, data);
		}
		else if (data > r->data)
		{
			r->right = deleteNode(r->right, data);
		}
		else
		{
			if (r->left == NULL)
			{
				Node *temp = r->right;
				delete r;
				return temp;
			}
			else if (r->right == NULL)
			{
				Node *temp = r->left;
				delete r;
				return temp;
			}
			else
			{
				Node *temp = getMin(r->right);
				r->data = temp->data;
				r->right = deleteNode(r->right, temp->data);
			}
		}
		return r;
	}

	Node *constructBST(int pre[], int start, int end)
	{
		if (start > end)
		{
			return NULL;
		}

		Node *n = new Node(pre[start]);
		int i;
		for (i = start; i <= end; i++)
		{
			if (pre[i] > n->data)
			{
				break;
			}
		}

		n->left = constructBST(pre, start + 1, i - 1);
		n->right = constructBST(pre, i, end);
		return n;
	}

	Node *findInorderPredecessor(Node *r, Node *p, int data)
	{
		if (r == NULL)
		{
			return p;
		}

		if (r->data == data)
		{
			if (r->left != NULL)
			{
				return getMax(r->left);
			}
		}
		else if (data < r->data)
		{
			return findInorderPredecessor(r->left, p, data);
		}
		else
		{
			p = r;
			return findInorderPredecessor(r->right, p, data);
		}
		return p;
	}

	bool isValidBST()
	{
		int n = count(root);
		int *arr = new int[n];
		fillArrayInorder(arr, root);
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				return false;
			}
		}
		return true;
	}

	void fillArrayInorder(int *arr, Node *r)
	{
		static int i = 0;
		if (r == NULL)
		{
			return;
		}
		fillArrayInorder(arr, r->left);
		arr[i] = r->data;
		i++;
		fillArrayInorder(arr, r->right);
	}
};

int main()
{
	BST tree;
	tree.insert(10);
	tree.insert(60);
	tree.insert(2);
	tree.insert(5);
	tree.insert(45);
	tree.insert(25);
	tree.inorder(tree.root);
	cout << endl;
	tree.search(5);
	cout << "Height: " << tree.height(tree.root) << endl;
	cout << "Count: " << tree.count(tree.root) << endl;
	cout << "Min Value: " << tree.getMin(tree.root)->data << endl;
	cout << "Deleting 60" << endl;
	tree.deleteNode(tree.root, 25);
	tree.inorder(tree.root);

	int arr[] = {15, 10, 8, 12, 20, 16, 25};
	int size = sizeof(arr) / sizeof(arr[0]);
	BST tree2;
	tree2.root = tree2.constructBST(arr, 0, size - 1);
	cout << endl;
	tree2.inorder(tree2.root);
	cout << "\nMax: " << tree2.getMax(tree2.root)->data << endl;
	cout << tree2.findInorderPredecessor(tree2.root, NULL, 10)->data << endl;
	cout << tree2.isValidBST() << endl;
	return 0;
}
