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
                    cout << "No duplicated allowed" << endl;
                }
                else if ((data < temp->data) && (temp->left == NULL))
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
};

int main()
{
    BST tree;
    tree.insert(25);
    tree.insert(22);
    tree.insert(32);
    tree.insert(18);
    tree.insert(21);
    tree.insert(30);
    tree.insert(35);

    cout << "Preorder : ";
    tree.preorder(tree.root);

    cout << "\nInorder  : ";
    tree.inorder(tree.root);

    cout << "\nPostorder: ";
    tree.postorder(tree.root);

    return 0;
}