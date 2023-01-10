// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 10

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

class BST{
    public:
        Node *root;

        BST(){
            root = NULL;
        }

        bool isEmpty(){
            if(root == NULL){
                return true;
            }else{
                return false;
            }
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
            return r;
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

        bool isBST(){
            int n = countNodes(root);
            int *arr = new int[n];
            fillInorder(root, arr);
            return(isSorted(arr, n));
        }

        void fillInorder(Node *r, int *arr){
            static int i = 0;
            if(r == NULL){
                return;
            }
            fillInorder(r->left, arr);
            arr[i] = r->data;
            i++;
            fillInorder(r->right, arr);
        }

        bool isSorted(int *arr, int n){
            for(int i=0;i<n-1;i++){
                if(arr[i] > arr[i+1]){
                    return false;
                }
            }
            return true;
        }

        int countNodes(Node *r){
            if(r == NULL){
                return 0;
            }else{
                int leftCount = countNodes(r->left);
                int rightCount = countNodes(r->right);
                return(leftCount + rightCount + 1);
            }
        }

        bool isBalanced(Node *r){
            if(r == NULL){
                return true;
            }
            if(getBalanceFactor(r) < -1 || getBalanceFactor(r) > 1){
                return false;
            }
            isBalanced(r->left);
            isBalanced(r->right);
        }

        bool isAVL(){
            if(isBST() && isBalanced(root)){
                return true;
            }else{
                return false;
            }
        }
};

int main(){
    BST tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 23);
    if(tree.isBST()){
        cout << "It is a BST Tree ";
        if(tree.isAVL()){
            cout << "and AVL Tree" << endl;
        }else{
            cout << "but not AVL" << endl;
        }
    }else{
        cout << "It is not BST and not AVL" << endl;
    }
    return 0;
}