#include <bits/stdc++.h>
vector<int> reverse(vector<int>v){
   int s = 0;
   int e = v.size()-1;
   while(s<e){
       swap(v[s] , v[e]);
       s++;
       e--;
   }    
   return v;
} 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> sum;
	int num1=0, num2=0;
	for(int i=0; i<n; i++){
		num1 = num1 *10 + a[i];
	}
	for(int i=0; i<m; i++){
		num2 = num2 *10 + b[i];
	}
	int res = num1 + num2;
	while(res){
		sum.push_back(res%10);
		res = res/10;
	}
	return reverse(sum);
}
