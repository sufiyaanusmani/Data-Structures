// Sufiyaan Usmani

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        
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

        void printBalanceFactors(Node *r){
            if(r == NULL){
                return;
            }
            cout << "Balance Factor of " << r->data << ": " << getBalanceFactor(r) << endl;
            printBalanceFactors(r->left);
            printBalanceFactors(r->right);
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

        Node *remove(Node *r, int data){
            if(r == NULL){
                return NULL;
            }else if(data < r->data){
                r->left = remove(r->left, data);
            }else if(data > r->data){
                r->right = remove(r->right, data);
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
                    r->right = remove(r->right, temp->data);
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

        Node * getMinNode(Node *r){
            Node *temp = r;
            while(temp->left != NULL){
                temp = temp->left;
            }
            return temp;
        }

        void preOrder(Node *r){
            if(r == NULL){
                return;
            }
            cout << r->data << "  ";
            preOrder(r->left);
            preOrder(r->right);
        }
};

int main(){
    AVL tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.printBalanceFactors(tree.root);
    cout << endl;
    tree.preOrder(tree.root);
    cout << endl;

    tree.root = tree.remove(tree.root, 10);
    tree.printBalanceFactors(tree.root);
    cout << endl;
    tree.preOrder(tree.root);
    return 0;
}