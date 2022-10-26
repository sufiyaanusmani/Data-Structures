#include <iostream>
using namespace std;

void merge(int mergedArray[], int arr1[], int arr2[], int size1, int size2){
	int i, j, k;
	i = j = k = 0;
	while(i < size1 && j < size2){
		if(arr1[i] < arr2[j]){
			mergedArray[k] = arr1[i];
			k++;
			i++;
		}else{
			mergedArray[k] = arr2[j];
			j++;
			k++;
		}
	}
	for(;i<size1;i++){
		mergedArray[k] = arr1[i];
		k++;
	}
	for(;j<size1;j++){
		mergedArray[k] = arr2[j];
		k++;
	}
}

void print(int arr[], int size){
	for(int i=0;i<size;i++){
		cout << arr[i] << "   ";
	}
	cout << endl;
}

int main(){
	int arr1[] = {2, 5, 6, 7, 8};
	int arr2[] = {1, 3, 5, 9};
	
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	
	int *mergedArray = new int[size1+size2];
	
	merge(mergedArray, arr1, arr2, size1, size2);
	print(mergedArray, size1+size2);
	delete[] mergedArray;
	return 0;
}

