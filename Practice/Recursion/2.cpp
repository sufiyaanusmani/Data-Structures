// Write a program in C to calculate the sum of numbers from 1 to n using recursion.
#include <iostream>
using namespace std;

int sum(int num){
	static int total = 0;
	if(num == 1){
		return 1;
	}else{
		return(num + sum(num - 1));
	}
}

int main(){
	cout << sum(5) << endl;
	return 0;
}

