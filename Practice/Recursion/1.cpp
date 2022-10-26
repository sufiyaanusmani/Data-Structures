// Write a program in C to print first 50 natural numbers using recursion.

#include <iostream>
using namespace std;

void print(int num){
	if(num <= 50){
		cout << num << "  ";
		print(num+1);
	}
}

int main(){
	print(1);
	return 0;
}

