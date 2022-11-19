// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int data){
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
                cout << "No duplicates allowed" << endl;
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
                    Node *temp = getMin(r->right);
                    r->data = temp->data;
                    r->right = deleteNode(r->right, temp->data);
                }
            }

            int bf = getBalanceFactor(r);

            if(bf == 2 && getBalanceFactor(r->left) >= 0){
                return rightRotate(r);
            }
            if(bf == 2 && getBalanceFactor(r->left) == -1){
                r->left = leftRotate(r->left);
                return rightRotate(r);
            }
            if(bf == -2 && getBalanceFactor(r->right) <= 0){
                return leftRotate(r);
            }
            if(bf == -2 && getBalanceFactor(r->right) == 1){
                r->right = rightRotate(r->right);
                return leftRotate(r);
            }
        }

        Node *getMin(Node *n){
            Node *temp = n;
            while(temp->left != NULL){
                temp = temp->left;
            }
            return temp;
        }

        void printBalanceFactors(Node *r){
            if(r == NULL){
                return;
            }
            cout << getBalanceFactor(r) << endl;
            printBalanceFactors(r->left);
            printBalanceFactors(r->right);
        }
};

int main(){
    AVL tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);

    tree.printBalanceFactors(tree.root);
    return 0;
}