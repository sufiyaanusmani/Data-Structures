// Sufiyaan Usmani

#include <iostream>
#include <queue>
using namespace std;

class Stack{
	private:
		queue<int> q;
		queue<int> temp;
	public:
		bool empty(){
			if(q.empty()){
				return true;
			}else{
				return false;
			}
		}

		void push(int data){
			q.push(data);
		}

		void pop(){
			int s = q.size();
			for(int i=0;i<s-1;i++){
				int num = q.front();
				q.pop();
				temp.push(num);
			}
			q.pop();
			while(!temp.empty()){
				int num = temp.front();
				temp.pop();
				q.push(num);
			}
		}

		int top(){
			return q.back();
		}
};

int main(){
	Stack stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);
	while(!stack.empty()){
		cout << stack.top() << endl;
		stack.pop();
	}
	return 0;
}