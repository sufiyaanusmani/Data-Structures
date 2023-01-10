// Sufiyaan Usmani

#include <iostream>
#include <stack>
using namespace std;

class Queue{
	private:
		stack<int> st;
		stack<int> temp;
	public:

		bool empty(){
			if(st.empty()){
				return true;
			}else{
				return false;
			}
		}

		void enqueue(int data){
			st.push(data);
		}

		void dequeue(){
			if(!st.empty()){
				while(!st.empty()){
					int num = st.top();
					st.pop();
					temp.push(num);
				}

				temp.pop();

				while(!temp.empty()){
					int num = temp.top();
					temp.pop();
					st.push(num);
				}
			}
		}

		int front(){
			while(!st.empty()){
				int num = st.top();
				st.pop();
				temp.push(num);
			}

			int data = temp.top();

			while(!temp.empty()){
				int num = temp.top();
				temp.pop();
				st.push(num);
			}
			return data;
		}
};

int main(){
	Queue queue;
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	queue.enqueue(40);
	queue.enqueue(50);

	while(!queue.empty()){
		cout << queue.front() << endl;
		queue.dequeue();
	}
	return 0;
}