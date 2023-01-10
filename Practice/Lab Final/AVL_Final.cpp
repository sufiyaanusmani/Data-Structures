// Sufiyaan Usmani

#include <iostream>
#include <vector>
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
                int a = height(r->left);
                int b = height(r->right);
                if(a > b){
                    return(a + 1);
                }else{
                    return(b + 1);
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

        Node *rightRotate(Node *r){
            Node *x = r->left;
            Node *temp = x->right;
            x->right = r;
            r->left = temp;
            return x;
        }

        Node *leftRotate(Node *r){
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
            cout << r->data << ": " << getBalanceFactor(r) << endl;
            preOrder(r->left);
            preOrder(r->right);
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

        Node *search(Node *r, int data){
            if(r == NULL || r->data == data){
                return r;
            }else if(data < r->data){
                return search(r->left, data);
            }else{
                return search(r->right, data);
            }
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

        int count(Node *r){
            if(r == NULL){
                return 0;
            }
            return count(r->left) + count(r->right) + 1;
        }

        void printGivenLevel(Node *r, int i){
            if(r == NULL){
                return;
            }else if(i == 0){
                cout << r->data << "  ";
            }else{
                printGivenLevel(r->left, i - 1);
                printGivenLevel(r->right, i - 1);
            }
        }

        void levelOrder(Node *r){
            int h = height(r);
            for(int i=0;i<=h;i++){
                printGivenLevel(r, i);
                cout << endl;
            }
        }

        void fillInorder(Node *r, vector<int> &arr){
            if(r == NULL){
                return;
            }
            fillInorder(r->left, arr);
            arr.push_back(r->data);
            fillInorder(r->right, arr);
        }

        int findInorderPredessor(int data){
            vector<int> arr;
            arr.resize(count(root));
            fillInorder(root, arr);
            for(int i=0;i<arr.size();i++){
                if(arr[i] == data){
                    return arr[i-1];
                }
            }
            return -1;
        }
};

int main(){
    AVL tree;
    tree.root = tree.insert(tree.root, 15);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 8);
    tree.root = tree.insert(tree.root, 12);
    tree.root = tree.insert(tree.root, 16);
    tree.root = tree.insert(tree.root, 25);
    
    // tree.preOrder(tree.root);
    // cout << endl;
    // tree.root = tree.deleteNode(tree.root, 40);
    // cout << endl;
    // tree.preOrder(tree.root);
    // cout << endl << tree.count(tree.root) << endl;
    // tree.levelOrder(tree.root);
    cout << tree.findInorderPredessor(20);
    return 0;

}