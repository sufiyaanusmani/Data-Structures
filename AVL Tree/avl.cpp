// Sufiyaan Usmani

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

        Node * insert(Node *r, int data){
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

        int height(Node *r){
            if(r == NULL){
                return -1;
            }else{
                int lHeight = height(r->left);
                int rHeight = height(r->right);
                if(lHeight > rHeight){
                    return (lHeight+1);
                }else{
                    return (rHeight+1);
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

        Node * rightRotate(Node *r){
            Node *x = r->left;
            Node *temp = x->right;

            x->right = r;
            r->left = temp;

            return x;
        }

        Node * leftRotate(Node *r){
            Node *x = r->right;
            Node *temp = x->left;

            x->left = r;
            r->right = temp;

            return x;
        }

        void preOrder(Node *r){
            if(r == NULL){
                return;
            }
            cout << r->data << "  ";
            preOrder(r->left);
            preOrder(r->right);
        }

        void inOrder(Node *r){
            if(r == NULL){
                return;
            }
            inOrder(r->left);
            cout << r->data << "  ";
            inOrder(r->right);
        }

        void postOrder(Node *r){
            if(r == NULL){
                return;
            }
            postOrder(r->left);
            postOrder(r->right);
            cout << r->data << "  ";
        }

        Node * minNode(Node *r){
            Node *temp = r;
            while(temp->left != NULL){
                temp = temp->left;
            }
            return temp;
        }

        Node * deleteNode(Node *r, int data){
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
                    Node *temp = minNode(r->right);
                    r->data = temp->data;
                    r->right = deleteNode(r->right, temp->data);
                }
            }

            int bf = getBalanceFactor(r);
            if(bf == 2 && getBalanceFactor(r->left) >= 0){
                return rightRotate(r);
            }
            if(bf == -2 && getBalanceFactor(r->right) <= 0){
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

        void printBalanceFactors(Node *r){
            if(r == NULL){
                return;
            }
            cout << "Balance Factor of " << r->data << ": " << getBalanceFactor(r) << endl;
            printBalanceFactors(r->left);
            printBalanceFactors(r->right);
        }
};

int main(){
    AVL tree;
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 25);

    tree.preOrder(tree.root);
    cout << endl;
    tree.printBalanceFactors(tree.root);
    tree.deleteNode(tree.root, 50);
    cout << endl;
    tree.printBalanceFactors(tree.root);
    return 0;
}