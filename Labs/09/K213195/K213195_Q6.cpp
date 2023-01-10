// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 6

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stack>
using namespace std;

class TextEditor{
    private:
        stack<char> st1, st2;
        // st1 is main stack where string is stored
        // if undo, then top character is popped from st1 and pushed to st2
        // if redo, then top character is popped from st2 and pushed to st1 
    public:
        TextEditor(string text){
            for(int i=0;i<text.length();i++){
                st1.push(text[i]);
            }
        }

        void print(){
            stack<char> temp;
            while(!st1.empty()){
                temp.push(st1.top());
                st1.pop();
            }
            while(!temp.empty()){
                cout << temp.top();
                st1.push(temp.top());
                temp.pop();
            }
            cout << endl;
        }

        void undo(){
            if(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }

        void redo(){
            if(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
};

int main(){
    string str;
    char ch;
    cout << "Enter text: ";
    getline(cin, str);
    TextEditor editor(str);
    cout << "Press 1 to undo and 2 to redo" << endl;
    while(1){
        ch = getch();
        if(ch == '1'){
            editor.undo();
            editor.print();
        }else if(ch == '2'){
            editor.redo();
            editor.print();
        }
    }
    return 0;
}