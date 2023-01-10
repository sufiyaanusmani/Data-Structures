// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 2

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
private:
    Node *top;
public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty(){
        if(top == NULL){
            return true;
        }else{
            return false;
        }
    }

    void printForward(){
        // from bottom to top
        Stack temp;
        while(!isEmpty()){
            temp.push(peek());
            pop();
        }
        while(!temp.isEmpty()){
            cout << temp.peek() << "  ";
            push(temp.peek());
            temp.pop();
        }
        cout << endl;
    }

    void printReversed(){
        // from top to bottom
        Stack temp;
        while(!isEmpty()){
            cout << peek() << "  ";
            temp.push(peek());
            pop();
        }
        while(!temp.isEmpty()){
            push(temp.peek());
            temp.pop();
        }
        cout << endl;
    }

    void push(int data)
    {
        Node *n = new Node(data);
        if (n == NULL)
        {
            // if heap is full
            cout << "Heap Overflow" << endl;
        }
        else
        {
            n->next = top;
            top = n;
        }
    }

    int pop()
    {
        int x = -1;
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            x = temp->data;
            delete temp;
        }
        return x;
    }

    int peek(){
        if(top == NULL){
            return -1;
        }else{
            return top->data;
        }
    }
};

int main(){
    Stack stack;
    // part 1
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    stack.push(100);

    cout << "Printing stack in forward direction:" << endl;
    stack.printForward();

    cout << "\nPrinting stack in reversed direction:" << endl;
    stack.printReversed();

    cout << "\nPopping " << stack.peek() << endl;
    stack.pop();
    return 0;
}