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
        if (isEmpty())
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
                    cout << "Value already inserted" << endl;
                    return;
                }
                else if ((data < temp->data) && (temp->left == NULL))
                {
                    temp->left = n;
                    cout << "Value inserted to the left of: " << temp->data << endl;
                    break;
                }
                else if (data < temp->data)
                {
                    temp = temp->left;
                }
                else if ((data > temp->data) && (temp->right == NULL))
                {
                    temp->right = n;
                    cout << "Value inserted to the right of: " << temp->data << endl;
                    break;
                }
                else if (data > temp->data)
                {
                    temp = temp->right;
                }
            }
        }
    }

    Node *insertRecursive(int data, Node *r)
    {
        if (r == NULL)
        {
            r = new Node(data);
            return r;
        }

        if (data < r->data)
        {
            r->left = insertRecursive(data, r->left);
        }
        else if (data > r->data)
        {
            r->right = insertRecursive(data, r->right);
        }
        else
        {
            cout << "Value already inserted" << endl;
        }
        return r;
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

    int search(int data)
    {
        if (root == NULL)
        {
            return -1;
        }
        else
        {
            Node *temp = root;
            while (temp != NULL)
            {
                if (temp->data == data)
                {
                    return temp->data;
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
            return -1;
        }
    }

    int searchRecursive(Node *r, int data)
    {
        if (r == NULL)
        {
            return -1;
        }
        if (r->data == data)
        {
            return r->data;
        }

        if (data < r->data)
        {
            return searchRecursive(r->left, data);
        }
        else
        {
            return searchRecursive(r->right, data);
        }
    }

    int count(Node *r)
    {
        int lCount, rCount;
        if (r == NULL)
        {
            return 0;
        }
        lCount = count(r->left);
        rCount = count(r->right);
        return (lCount + rCount + 1);
    }

    int height(Node *r)
    {
        int lCount, rCount;
        if (r == NULL)
        {
            return 0;
        }
        lCount = height(r->left);
        rCount = height(r->right);
        if (lCount > rCount)
        {
            return (lCount + 1);
        }
        else
        {
            return (rCount + 1);
        }
    }

    Node *minNode(Node *r)
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
                // one or no child
                Node *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                // one or no child
                Node *temp = r->right;
                delete r;
                return temp;
            }
            else
            {
                // two children
                // getting inorder successor (smallest value in the right subtree)
                Node *temp = minNode(r->right);
                r->data = temp->data;
                r->right = deleteNode(r->right, temp->data);
            }
        }
    }
};

int main()
{
    BST tree;
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    // tree.root = tree.insertRecursive(10, tree.root);
    // tree.root = tree.insertRecursive(30, tree.root);
    // tree.root = tree.insertRecursive(5, tree.root);
    tree.preorder(tree.root);
    cout << endl;
    tree.inorder(tree.root);
    cout << endl;
    tree.postorder(tree.root);
    cout << endl;
    tree.insert(40);

    int data = tree.search(30);
    if (data != -1)
    {
        cout << "Value found: " << data << endl;
    }
    else
    {
        cout << "Value not found" << endl;
    }

    data = tree.searchRecursive(tree.root, 10);
    if (data != -1)
    {
        cout << "Value found: " << data << endl;
    }
    else
    {
        cout << "Value not found" << endl;
    }

    tree.inorder(tree.root);
    cout << "\nCount: " << tree.count(tree.root) << endl;
    cout << "Height: " << tree.height(tree.root) << endl;
    return 0;
}