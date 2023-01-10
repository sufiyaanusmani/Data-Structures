// Sufiyaan Usmani
// 21K-3195
// BCS-3J
// Question 1(a)

#include <iostream>
using namespace std;

void print(int n, int previous){
	static int diff = 1;
	int num;
	
	// base case
	if(n == 0){
		return;
	}
	
	num = previous + diff;
	cout << num << "  ";
	diff++;
	print(n-1, num);
	
}

int main(){
	int n;
	cout << "Enter number of elements to print in sequence: ";
	cin >> n;
	cout << "\nSequence: ";
	print(n, 0);
	return 0;
}
