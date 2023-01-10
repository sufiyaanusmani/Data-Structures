// Sufiyaan Usmani

#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        Node *left;
        int data;
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

        void insert(int data){
            Node *n = new Node(data);
            if(root == NULL){
                root = n;
            }else{
                Node *temp = root;
                while(temp != NULL){
                    if(temp->data == data){
                        cout << "Duplicated not allowed" << endl;
                        break;
                    }else if((data < temp->data) && (temp->left == NULL)){
                        temp->left = n;
                        break;
                    }else if(data < temp->data){
                        temp = temp->left;
                    }else if((data > temp->data) && (temp->right == NULL)){
                        temp->right = n;
                        break;
                    }else{
                        temp = temp->right;
                    }
                }
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
                cout << "Duplicated not allowed" << endl;
                return r;
            }
            return r;
        }

        Node *search(int data){
            if(root == NULL){
                cout << "Empty" << endl;
                return NULL;
            }else{
                Node *temp = root;
                while(temp != NULL){
                    if(temp->data == data){
                        cout << "Found" << endl;
                        return temp;
                    }else if(data < temp->data){
                        temp = temp->left;
                    }else{
                        temp = temp->right;
                    }
                }
                cout << "Not found" << endl;
                return NULL;
            }
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

        void printGivenLevel(Node *r, int i){
            if(r == NULL){
                return;
            }else if(i == 0){
                cout << r->data << "  ";
            }else{
                printGivenLevel(r->left, i-1);
                printGivenLevel(r->right, i-1);
            }
        }

        void printLevelOrder(Node *r){
            int h = height(r);
            for(int i=0;i<=h;i++){
                printGivenLevel(r, i);
                cout << endl;
            }
        }

        int count(Node *r){
            if(r == NULL){
                return 0;
            }
            return count(r->left) + count(r->right) + 1;
        }

        void printGivenLevel(Node *r, int i, vector<int> &arr, int size, int &j){
            if(j == size){
                return;
            }else if(r == NULL){
                arr[j] = -1;
                j++;
            }else if(i == 0){
                // cout << r->data << "  ";
                arr[j] = r->data;
                j++;
            }else{
                printGivenLevel(r->left, i-1, arr, size, j);
                printGivenLevel(r->right, i-1, arr, size, j);
            }
        }

        bool levelOrderDo(Node *r){
            int j = 0;
            int h = height(r);
            vector<int> arr;
            int s = count(root);
            arr.resize(100, -1);
            for(int i=0;i<=h;i++){
                printGivenLevel(r, i, arr, 100, j);
            }
            for(int i=0;i<j;i++){
                if(arr[j] == -1){
                    return false;
                }
            }
            return true;
        }
};

int main(){
    BST tree1;
    // tree1.insert(40);
    // tree1.insert(20);
    // tree1.insert(50);
    // tree1.insert(90);
    // tree1.inOrder(tree1.root);
    // tree1.search(20);
    // tree1.root = tree1.deleteNode(tree1.root, 50);
    // cout << endl;
    // tree1.inOrder(tree1.root);
    // cout << endl;
    // tree1.printLevelOrder(tree1.root);
    cout << "\n----------------" << endl;
    BST tree2;
    tree2.root = tree2.insert(tree2.root, 40);
    tree2.root = tree2.insert(tree2.root, 20);
    tree2.root = tree2.insert(tree2.root, 50);
    tree2.root = tree2.insert(tree2.root, 90);
    // tree2.inOrder(tree2.root);
    // tree2.search(20);
    cout << endl;
    if(tree2.levelOrderDo(tree2.root)){
        cout << "Complete" << endl;
    }else{
        cout << "Not Complete" << endl;
    }
    return 0;
}