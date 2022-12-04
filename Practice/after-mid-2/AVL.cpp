// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

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
                int left = height(r->left);
                int right = height(r->right);
                if(left > right){
                    return(left + 1);
                }else{
                    return(right + 1);
                }
            }
        }

        int getBalanceFactor(Node *r){
            if(r == NULL){
                return -1;
            }else{
                return(height(r->left) - height(r->right));
            }
        }

        Node *leftRotate(Node *r){
            Node *x = r->right;
            Node *temp = x->left;
            x->left = r;
            r->right = temp;
            return x;
        }

        Node *rightRotate(Node *r){
            Node *x = r->left;
            Node *temp = x->right;
            x->right = r;
            r->left = temp;
            return x;
        }

        void printBalanceFactors(Node *r){
            if(r == NULL){
                return;
            }
            cout << "Balance factor of " << r->data << ": " << getBalanceFactor(r) << endl;
            printBalanceFactors(r->left);
            printBalanceFactors(r->right);
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
                cout << "duplicates not allowed" << endl;
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

        Node *getMinNode(Node *r){
            Node *temp = r;
            while(temp->left != NULL){
                temp = temp->left;
            }
            return temp;
        }

        Node *deleteNode(Node *r, int data){
            if(r == NULL){
                return NULL;
            }else if(data < r->data){
                r->left = deleteNode(r->left, data);
            }else if(data > r->data){
                r->right = deleteNode(r->right, data);
            }else{
                if(r->left == NULL){
                    Node *temp = r->right;
                    delete r;
                    return temp;
                }else if(r->right == NULL){
                    Node *temp = r->left;
                    delete r;
                    return temp;
                }else{
                    Node *temp = getMinNode(r->right);
                    r->data = temp->data;
                    r->right = deleteNode(r->right, temp->data);
                }
            }

            int bf = getBalanceFactor(r);
            if(bf == 2 && getBalanceFactor(r->left) >= 0){
                return rightRotate(r);
            }
            if(bf == -2 && getBalanceFactor(r->right) <= -1){
                return leftRotate(r);
            }
            if(bf == 2 && getBalanceFactor(r->left) == -1){
                r->left = leftRotate(r->left);
                return rightRotate(r);
            }
            if(bf == -2 && getBalanceFactor(r->right) == 1){
                r->right = rightRotate(r->right);
                return leftRotate(r);
            }

            return r;
        }
};

int main(){
    AVL tree;
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 6);
    tree.printBalanceFactors(tree.root);
    tree.root = tree.deleteNode(tree.root, 4);
    tree.printBalanceFactors(tree.root);
    return 0;
}