// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 7

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str){
    stack<char> st;
    for(int i=0;i<str.length();i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            st.push(str[i]);
        }else if(str[i] == ')'){
            if(st.top() == '('){
                st.pop();
            }else{
                return false;
            }
        }else if(str[i] == '}'){
            if(st.top() == '{'){
                st.pop();
            }else{
                return false;
            }
        }else if(str[i] == ']'){
            if(st.top() == '['){
                st.pop();
            }else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }else{
        return false;
    }
}

int main(){
    string str1 = "{()}[]";
    cout << "String: " << str1 << endl;
    if(isValid(str1)){
        cout << "String is valid" << endl;
    }else{
        cout << "String is invalid" << endl;
    }

    string str2 = "{(}[";
    cout << "\nString: " << str2 << endl;
    if(isValid(str2)){
        cout << "String is valid" << endl;
    }else{
        cout << "String is invalid" << endl;
    }
    return 0;
}