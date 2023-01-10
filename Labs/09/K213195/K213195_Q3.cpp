// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 3

#include <iostream>
#include <stack>
using namespace std;


int getPrecedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

string infixToPostfix(string infix)
{
	stack<char> st;
	string result = "";

	for (int i = 0; i < infix.length(); i++) {
		char ch = infix[i];

		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
			result += ch;
        }else if (ch == '('){
			st.push('(');
		}else if (ch == ')'){
			while (st.top() != '('){
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while (!st.empty() && getPrecedence(infix[i]) <= getPrecedence(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(ch);
		}
	}

    // Popping remaining elements
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	return result;
}

int main()
{
	string infix = "a+b*(c^d-e)^(f+g*h)-i";
	cout << "Infix: " << infix << endl;
	cout << "Postfix: " << infixToPostfix(infix) << endl;
	return 0;
}
