
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
        right = left = NULL;
    }
};

class BinaryTree
{
private:
    Node *root;
    void preorder(Node *node)
    {
        if (node == NULL)
        {
        }
        cout << node->data << "   ";
        preorder(node->left);
        preorder(node->right);
    }
    void inorder(Node *node)
    {
        if (node == NULL)
        {
        }
        inorder(node->left);
        cout << node->data << "   ";
        inorder(node->right);
    }
    void postorder(Node *node)
    {
        if (node == NULL)
        {
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->data << "   ";
    }
};

int main()
{

    return 0;
}