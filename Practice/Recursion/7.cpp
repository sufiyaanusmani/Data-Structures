// Write a program in C to find the sum of digits of a number using recursion
#include <iostream>
using namespace std;

int sum(int num){
	if(num == 0){
		return 0;
	}else{
		return((num % 10) + sum(num / 10));
	}
}

int main(){
	cout << sum(25) << endl;
	return 0;
}

