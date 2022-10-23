// Sufiyaan Usmani

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
private:
    Node *root;

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

    bool searchRecursive(Node *n, int data)
    {
        // base case 1
        if (n == NULL)
        {
            return false;
        }

        // base case 2
        if (n->data == data)
        {
            return true;
        }

        if (data < n->data)
        {
            return searchRecursive(n->left, data);
        }
        else
        {
            return searchRecursive(n->right, data);
        }
    }

    bool searchIterative(int data)
    {
        Node *n = root;
        while (n != NULL)
        {
            if (n->data == data)
            {
                return true;
            }
            else if (data < n->data)
            {
                n = n->left;
            }
            else
            {
                n = n->right;
            }
        }
        return false;
    }

    Node *insert(Node *n, int data)
    {
        if (n == NULL)
        {
            n = new Node(data);
            return n;
        }
        if (data < n->data)
        {
            n->left = insert(n->left, data);
        }
        else if (data > n->data)
        {
            n->right = insert(n->right, data);
        }
        return n;
    }

    void preorder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        cout << n->data << "  ";
        preorder(n->left);
        preorder(n->right);
    }

    void inorder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        inorder(n->left);
        cout << n->data << "  ";
        inorder(n->right);
    }

    void postorder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        postorder(n->left);
        postorder(n->right);
        cout << n->data << "  ";
    }

public:
    BST()
    {
        root = NULL;
    }

    bool search(int data)
    {
        return searchRecursive(root, data);
    }

    void insert(int data)
    {
        if (search(data))
        {
            cout << "Data already exists" << endl;
        }
        else
        {
            root = insert(root, data);
        }
    }

    void preorderTraversal()
    {
        preorder(root);
        cout << endl;
    }

    void inorderTraversal()
    {
        inorder(root);
        cout << endl;
    }
    void postorderTraversal()
    {
        postorder(root);
        cout << endl;
    }
};

int main()
{
    BST tree;
    tree.insert(10);
    tree.insert(8);
    tree.insert(30);
    tree.preorderTraversal();
    tree.inorderTraversal();
    tree.postorderTraversal();
    return 0;
}