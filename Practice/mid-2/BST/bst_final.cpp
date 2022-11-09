// Sufiyaan Usmani

#include <iostream>
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
                if (temp->data == data)
                {
                    cout << "Duplicates not allowed" << endl;
                    break;
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

    Node *insertRecursive(Node *r, int data)
    {
        if (r == NULL)
        {
            r = new Node(data);
            return r;
        }

        if (data < r->data)
        {
            r->left = insertRecursive(r->left, data);
        }
        else if (data > r->data)
        {
            r->right = insertRecursive(r->right, data);
        }
        else
        {
            cout << "Duplicates not allowed" << endl;
            return r;
        }
        return r;
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
                if (data == temp->data)
                {
                    cout << "Found" << endl;
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
            cout << "Not found" << endl;
            return NULL;
        }
    }

    Node *searchRecursive(Node *r, int data)
    {
        if (r == NULL || data == r->data)
        {
            return r;
        }
        else if (data < r->data)
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

    Node *min(Node *r)
    {
        Node *temp = r;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node *max(Node *r)
    {
        Node *temp = r;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }

    int height(Node *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        else
        {
            int lHeight = height(r->left);
            int rHeight = height(r->right);
            if (lHeight > rHeight)
            {
                return (lHeight + 1);
            }
            else
            {
                return (rHeight + 1);
            }
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
                Node *temp = min(r->right);
                r->data = temp->data;
                r->right = deleteNode(r->right, temp->data);
            }
        }
        return r;
    }

    void printGivenLevel(Node *r, int i)
    {
        if (r == NULL)
        {
            return;
        }
        else if (i == 0)
        {
            cout << r->data << "  ";
        }
        else
        {
            printGivenLevel(r->left, i - 1);
            printGivenLevel(r->right, i - 1);
        }
    }

    void levelOrder(Node *r)
    {
        int h = height(r);
        for (int i = 0; i <= h; i++)
        {
            printGivenLevel(r, i);
        }
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
                return max(r->left);
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

    Node *findInorderSuccessor(Node *r, Node *p, int data)
    {
        if (r == NULL)
        {
            return p;
        }

        if (r->data == data)
        {
            if (r->right != NULL)
            {
                return min(r->right);
            }
        }
        else if (data < r->data)
        {
            p = r;
            return findInorderSuccessor(r->left, p, data);
        }
        else
        {
            return findInorderSuccessor(r->right, p, data);
        }
        return p;
    }

    int max(int x, int y)
    {
        if (x > y)
        {
            return x;
        }
        else
        {
            return y;
        }
    }

    int min(int x, int y)
    {
        if (x < y)
        {
            return x;
        }
        else
        {
            return y;
        }
    }

    Node *lowestCommonAncestor(Node *r, Node *x, Node *y)
    {
        if (r == NULL)
        {
            return NULL;
        }

        if (max(x->data, y->data) < r->data)
        {
            return lowestCommonAncestor(r->left, x, y);
        }
        else if (min(x->data, y->data) > r->data)
        {
            return lowestCommonAncestor(r->right, x, y);
        }
        return r;
    }

    void fillInorder(Node *r, int *arr)
    {
        static int i = 0;
        if (r == NULL)
        {
            return;
        }
        fillInorder(r->left, arr);
        arr[i] = r->data;
        i++;
        fillInorder(r->right, arr);
    }

    int kLargestElement(int k)
    {
        int size = count(root);
        int *arr = new int[size];
        fillInorder(root, arr);
        return arr[size - k];
    }

    void findFloorCeil(int data)
    {
        int floor, ceil;
        Node *temp = root;
        while (temp != NULL)
        {
            if (data == temp->data)
            {
                floor = ceil = temp->data;
                break;
            }
            else if (data < temp->data)
            {
                ceil = temp->data;
                temp = temp->left;
            }
            else
            {
                floor = temp->data;
                temp = temp->right;
            }
        }
        cout << "Floor: " << floor << endl;
        cout << "Ceil: " << ceil << endl;
    }

    bool printAncestors(Node *r, int data)
    {
        if (r == NULL)
        {
            return false;
        }
        if (r->data == data)
        {
            return true;
        }

        if (printAncestors(r->left, data) || printAncestors(r->right, data))
        {
            cout << r->data << "  ";
            return true;
        }

        return false;
    }

    void printDescendents(int data)
    {
        Node *r = search(data);
        inorder(r->left);
        inorder(r->right);
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
};

int main()
{
    BST tree1;
    // insertion
    tree1.insert(20);
    tree1.insert(30);
    tree1.insert(10);
    tree1.insert(50);
    tree1.inorder(tree1.root);
    cout << endl;
    tree1.insertRecursive(tree1.root, 10);
    tree1.insertRecursive(tree1.root, 2);
    tree1.insertRecursive(tree1.root, 15);
    tree1.insertRecursive(tree1.root, 25);
    tree1.inorder(tree1.root);
    cout << "\n\n";

    // searching
    tree1.search(10);
    tree1.search(30);
    tree1.search(7);
    tree1.search(25);
    cout << tree1.searchRecursive(tree1.root, 10)->data << endl;
    cout << tree1.searchRecursive(tree1.root, 30)->data << endl;
    // cout << tree1.searchRecursive(tree1.root, 7)->data << endl;
    cout << tree1.searchRecursive(tree1.root, 25)->data << endl;

    cout << "\nNodes: " << tree1.count(tree1.root) << endl;
    cout << "Min: " << tree1.min(tree1.root)->data << endl;
    cout << "Max: " << tree1.max(tree1.root)->data << endl;
    cout << "Height: " << tree1.height(tree1.root) << endl
         << endl;

    // deletion
    tree1.inorder(tree1.root);
    tree1.deleteNode(tree1.root, 30);
    tree1.deleteNode(tree1.root, 15);
    cout << endl;
    tree1.inorder(tree1.root);
    cout << endl;
    tree1.levelOrder(tree1.root);
    cout << endl
         << endl;

    cout << tree1.findInorderPredecessor(tree1.root, NULL, 50)->data << endl;
    cout << tree1.findInorderSuccessor(tree1.root, NULL, 25)->data << endl;
    cout << tree1.kLargestElement(3) << endl
         << endl;
    tree1.printAncestors(tree1.root, 10);
    cout << endl;
    tree1.printDescendents(20);
    cout << endl;
    return 0;
}