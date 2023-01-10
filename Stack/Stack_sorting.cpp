// Sufiyaan Usmani

#include <iostream>
#include <stack>
using namespace std;

stack<int> sortStack(stack<int> &st1){
	stack<int> temp;
	while(!st1.empty()){
		int num = st1.top();
		st1.pop();
		while(!temp.empty() && num > temp.top()){
			st1.push(temp.top());
			temp.pop();
		}
		temp.push(num);
	}
	return temp;
}

int main(){
	stack<int> st1;
	st1.push(31);
	st1.push(3);
	st1.push(5);
	st1.push(2);
	st1.push(56);
	st1.push(24);
	stack<int> st2 = sortStack(st1);
	while(!st2.empty()){
		cout << st2.top() << endl;
		st2.pop();
	}
	return 0;
}