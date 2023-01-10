// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 9

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data=0){
            this->data = data;
            left = right = NULL;
        }
};

class AVL{
    public:
        Node *root;

        AVL(){
            root = NULL;
        }

        bool isEmpty(){
            if(root == NULL){
                return true;
            }else{
                return false;
            }
        }

        int height(Node *r){
            if(r == NULL){
                return -1;
            }else{
                int leftHeight = height(r->left);
                int rightHeight = height(r->right);
                if(leftHeight > rightHeight){
                    return(leftHeight + 1);
                }else{
                    return(rightHeight + 1);
                }
            }
        }

        int getBalanceFactor(Node *r){
            if(r == NULL){
                return -1;
            }
            return(height(r->left) - height(r->right));
        }

        Node *insert(Node *r, int data){
            if(r == NULL){
                r = new Node(data);
                return r;
            }

            if(data < r->data){
                r->left = insert(r->left, data);
            }else if(data > r->data){
                r->right = insert(r->right, data);
            }else{
                cout << "Duplicates not allowed" << endl;
                return r;
            }

            int bf = getBalanceFactor(r);
            if(bf > 1 && data < r->left->data){
                return rightRotate(r);
            }
            if(bf < -1 && data > r->right->data){
                return leftRotate(r);
            }
            if(bf > 1 && data > r->left->data){
                r->left = leftRotate(r->left);
                return rightRotate(r);
            }
            if(bf < -1 && data < r->right->data){
                r->right = rightRotate(r->right);
                return leftRotate(r);
            }
            return r;
        }

        Node *leftRotate(Node *r){
            Node *y = r->right;
            Node *temp = y->left;

            y->left = r;
            r->right = temp;

            return y;
        }

        Node *rightRotate(Node *r){
            Node *x = r->left;
            Node *temp = x->right;

            x->right = r;
            r->left = temp;

            return x;
        }

        void printBalanceFactors(Node *r){
            // printing balance factors in preorder fashion
            if(r == NULL){
                return;
            }
            cout << "Balance factor of " << r->data << ": " << getBalanceFactor(r) << endl;
            printBalanceFactors(r->left);
            printBalanceFactors(r->right);
        }

        void inorder(Node *r){
            if(r == NULL){
                return;
            }
            inorder(r->left);
            cout << r->data << "  ";
            inorder(r->right);
        }
};

int main(){
    AVL tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 15);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 25);
    tree.inorder(tree.root);
    cout << "\n\n";
    tree.printBalanceFactors(tree.root);
    return 0;
}