#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;

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

    // PART (a)
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
                if (temp->data == data)
                {
                    cout << "Duplicates not allowed" << endl;
                    break;
                }
                else if (data < temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = n;
                        break;
                    }
                    temp = temp->left;
                }
                else if (data > temp->data)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = n;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
    }

    // PART (b)
    void insert(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            insert(arr[i]);
        }
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
};

int main()
{
    int arr[] = {15, 10, 20, 8, 12, 16, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    BST tree;
    tree.insert(arr, n);
    tree.inorder(tree.root);
    return 0;
}