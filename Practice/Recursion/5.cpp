// Write a program in C to count the digits of a given number using recursion.
#include <iostream>
using namespace std;

int digits(int num){
	static int count = 0;
	if(num == 0){
		return count;
	}else{
		count++;
		digits(num / 10);
	}
}

int main(){
	cout << digits(5047) << endl;
	return 0;
}

