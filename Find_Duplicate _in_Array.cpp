#include <bits/stdc++.h>
int findDuplicate(vector<int> &arr, int n){
	int count=0;
	sort(arr.begin(), arr.end());
	for(int i=0;  i<arr.size(); i++){
		if(arr[i]==arr[i+1]){
			count++;
			if(count == 1){
				return arr[i];
			}
		}
	}
}
