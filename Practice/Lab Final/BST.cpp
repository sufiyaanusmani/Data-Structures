// Sufiyaan Usmani

#include <iostream>
#include <stack>
#include <vector>
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
            return r;
        }

        int count(Node *r){
            if(r == NULL){
                return 0;
            }else{
                return count(r->left) + count(r->right) + 1;
            }
        }

        int height(Node *r){
            if(r == NULL){
                return -1;
            }else{
                int a = height(r->left);
                int b = height(r->right);
                if(a > b){
                    return(a+1);
                }else{
                    return(b+1);
                }
            }
        }

        void levelOrder(Node *r){
            int h = height(r);
            for(int i=0;i<=h;i++){
                printGivenLevel(i, r);
                cout << endl;
            }
        }

        void printGivenLevel(int i, Node *r){
            if(r == NULL){
                return;
            }else if(i == 0){
                cout << r->data << "  ";
            }else{
                printGivenLevel(i-1, r->left);
                printGivenLevel(i-1, r->right);
            }
        }

        Node *max(Node *r){
            Node *temp = r;
            while(r->right != NULL){
                r = r->right;
            }
            return r;
        }

        Node *findInorderPredecessor(Node *r, Node *p, int data){
            if(r == NULL){
                return p;
            }
            if(r->data == data){
                if(r->left == NULL){
                    return(max(r->left));
                }
            }else if(data < r->data){
                return findInorderPredecessor(r->left, p, data);
            }else{
                p = r;
                return findInorderPredecessor(r->right, p, data);
            }
            return p;
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

    void fillInorder(Node *r, vector<int> &arr){
        if(r == NULL){
            return;
        }
        fillInorder(r->left, arr);
        arr.push_back(r->data);
        fillInorder(r->right, arr);
    }

    void deleteRange(int start, int end){
        vector<int> arr;
        fillInorder(root, arr);
        for(int i=0;i<arr.size();i++){
            if(arr[i] < start || arr[i] > end){
                root = deleteNode(root, arr[i]);
            }
        }
    }
};

int main(){
    BST tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 1);
    tree.root = tree.insert(tree.root, 15);
    tree.inOrder(tree.root);
    cout << endl;
    tree.deleteRange(6, 15);
    tree.inOrder(tree.root);
    return 0;
}