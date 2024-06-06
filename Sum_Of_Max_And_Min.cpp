#include <bits/stdc++.h> 
int sumOfMaxMin(int arr[], int n){
	int max = 0; 
	int min = 0; 
	for(int i = 0; i < n; i++){
		if(arr[i] > arr[max])
			max = i;
		if(arr[i] < arr[min])
			min = i;
	}
	return arr[min] + arr[max];
}
