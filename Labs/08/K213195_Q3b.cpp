#include <iostream>
#include <stack>
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

    void preorderIterative()
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            stack<Node *> st;
            st.push(root);
            Node *temp;
            while (!st.empty())
            {
                temp = st.top();
                cout << temp->data << "  ";
                st.pop();

                if (temp->right != NULL)
                {
                    st.push(temp->right);
                }

                if (temp->left != NULL)
                {
                    st.push(temp->left);
                }
            }
        }
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

    cout << "Preorder Using Recursion: ";
    tree.preorder(tree.root);

    cout << "\nPreorder Using Iteration: ";
    tree.preorderIterative();

    return 0;
}