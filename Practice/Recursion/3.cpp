// Write a program in C to Print Fibonacci Series using recursion.
#include <iostream>
using namespace std;

int fibonacci(int n){
	if(n == 1 || n == 2){
		return 1;
	}else{
		return(fibonacci(n-1) + fibonacci(n-2));
	}
}

int main(){
	for(int i=1;i<=10;i++){
		cout << fibonacci(i) << endl;
	}	
	return 0;
}

