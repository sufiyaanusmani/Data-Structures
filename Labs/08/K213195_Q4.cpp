#include <iostream>
using namespace std;

// Logic: Inorder traversal of BST is always in sorted order
// so, inorder traversal of BST will be stored in array and array will be checked if it is sorted or not

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

    Node *min(Node *r)
    {
        Node *temp = r;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node *deleteNode(Node *r, int data)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else
        {
            if (data < r->data)
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
                    Node *temp = min(r->right);
                    r->data = temp->data;
                    r->right = deleteNode(r->right, temp->data);
                }
            }
        }
    }

    Node *deleteNode(Node *r, int start, int end)
    {
        // traversing BST in post order fashion so that all childs of a node are visited first
        if (r == NULL)
        {
            return NULL;
        }
        r->left = deleteNode(r->left, start, end);
        r->right = deleteNode(r->right, start, end);

        if (r->data < start)
        {
            Node *temp = r->right;
            delete r;
            return temp;
        }

        if (r->data > end)
        {
            Node *temp = r->left;
            delete r;
            return temp;
        }

        return r;
    }
};

int main()
{
    // valid BST
    BST tree;
    tree.insert(15);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(12);
    tree.insert(18);
    tree.insert(25);
    cout << "BST before deletion: ";
    tree.inorder(tree.root);
    tree.root = tree.deleteNode(tree.root, 9, 12);
    cout << endl;
    cout << "BST after deletion : ";
    tree.inorder(tree.root);

    return 0;
}