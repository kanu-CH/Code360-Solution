#include <bits/stdc++.h> 
bool isPerfectSquare(long long n) {
	int s=1; int e= n;
    int mid= s+(e-s)/2;
    while(s<=e){ 
        if(n%mid==0 && mid==n/mid)return true;
        if (mid > n/mid){ 
            e=mid-1;
        }
        else s= mid+1;
        mid= s+(e-s)/2;
    }
    return false;
}
