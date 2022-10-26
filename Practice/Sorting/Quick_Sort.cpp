#include <iostream>
#include <iomanip>
using namespace std;

int partition(int arr[], int l, int h){
	int pivot, start, end;
	pivot = arr[l];
	start = l;
	end = h;
	
	while(start < end){
		while(arr[start] <= pivot){
			start++;
		}
		while(arr[end] > pivot){
			end--;
		}
		if(start < end){
			swap(arr[start], arr[end]);
		}
	}	
	swap(arr[l], arr[end]);
	return end;
}

void quickSort(int arr[], int l, int h){
	int location;
	if(l < h){
		location = partition(arr, l, h);
		quickSort(arr, l, location-1);
		quickSort(arr, location+1, h);
	}
}

void print(int arr[], int size){
	for(int i=0;i<size;i++){
		cout << setw(2) << arr[i] << "   ";
	}
	cout << endl;
}

int main(){
	int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Before sorting: ";
	print(arr, size);
	
	quickSort(arr, 0, size-1);
	
	cout << "After sorting : ";
	print(arr, size);
	return 0;
}

