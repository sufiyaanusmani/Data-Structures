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

    Node *insert(Node *root, int data)
    {
        Node *t;
        if (root == NULL)
        {
            t = new Node(data);
            t->left = t->right = NULL;
            return t;
        }
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        return t;
    }

    void preorder(Node *t)
    {
        if (t != NULL)
        {
            cout << t->data << "  ";
            preorder(t->left);
            preorder(t->right);
        }
    }

    void inorder(Node *t)
    {
        if (t != NULL)
        {
            inorder(t->left);
            cout << t->data << "  ";
            inorder(t->right);
        }
    }

    void postorder(Node *t)
    {
        if (t != NULL)
        {
            postorder(t->left);
            postorder(t->right);
            cout << t->data << "  ";
        }
    }

    Node *search(Node *t, int data)
    {
        if (t == NULL)
        {
            return NULL;
        }
        if (data == t->data)
        {
            return t;
        }
        if (data < t->data)
        {
            return search(t->left, data);
        }
        if (data > t->data)
        {
            return search(t->right, data);
        }
    }
};

int main()
{

    return 0;
}