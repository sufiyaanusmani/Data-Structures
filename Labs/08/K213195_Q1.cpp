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

    void inorder(Node *r, int *arr)
    {
        static int i = 0;
        if (r == NULL)
        {
            return;
        }
        inorder(r->left, arr);
        arr[i] = r->data;
        i++;
        inorder(r->right, arr);
    }

    int countNodes(Node *r)
    {
        if (r == NULL)
        {
            return 0;
        }
        else
        {
            int lCount = countNodes(r->left);
            int rCount = countNodes(r->right);
            return (lCount + rCount + 1);
        }
    }

    bool isValidBST()
    {
        int count = countNodes(root);
        if (count == 0)
        {
            // if there are no nodes
            return true;
        }
        int *arr = new int[count];
        inorder(root, arr);
        if (isSorted(arr, count))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isSorted(int *arr, int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    bool autoGrader()
    {
        return isValidBST();
    }
};

int main()
{
    // valid BST
    BST tree1;
    Node *t1 = new Node(2);
    Node *t2 = new Node(4);
    Node *t3 = new Node(6);
    Node *t4 = new Node(8);
    tree1.root = t2;
    t2->left = t1;
    t2->right = t3;
    t3->right = t4;

    cout << "----- Tree 1 -----" << endl;
    if (tree1.autoGrader())
    {
        cout << "Points: 10" << endl;
    }
    else
    {
        cout << "Points: 0" << endl;
    }

    // invalid BST
    BST tree2;
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(5);
    Node *n4 = new Node(40);

    tree2.root = n1;
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;

    cout << "\n----- Tree 2 -----" << endl;
    if (tree2.autoGrader())
    {
        cout << "Points: 10" << endl;
    }
    else
    {
        cout << "Points: 0" << endl;
    }
    return 0;
}