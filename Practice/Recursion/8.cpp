// Write a program in C to get the largest element of an array using recursion.
#include <iostream>
using namespace std;

int largest(int arr[], int size){
	static int m = arr[0];
	static int i = 0;
	if(i < size){
		if(arr[i] > m){
			m = arr[i];
		}
		i++;
		largest(arr, size);
	}
	return m;
}

int main(){
	int arr[] = {5, 10, 45, 5, 33};
	cout << largest(arr, 5) << endl;
	return 0;
}

