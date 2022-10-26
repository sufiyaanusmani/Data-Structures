// Write a program in C to print the array elements using recursion.
#include <iostream>
using namespace std;

void print(int arr[], int size){
	static int i = 0;
	if(i < size){
		cout << arr[i] << endl;
		i++;
		print(arr, size);
	}
}

int main(){
	int arr[6] = {2, 4, 6, 8, 10, 12};
	print(arr, 6);
	return 0;
}

