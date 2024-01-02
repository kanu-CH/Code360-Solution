#include <bits/stdc++.h> 
bool valid(int t, vector<int> &rank, int m, int n)
{
	int cp = 0, tt, val, count = 0;
	
	for(int i = 0; i < n; i++)
	{
		tt = rank[i];
		count = 0;
		val = 1;
		
		while(tt <= t)
		{
			count++;
			val++;
			tt += (val*rank[i]);
		}
		
		cp += count;
		
		if(cp >= m) 
            return true;
	}
	return false;
}
int minCookTime(vector<int> &rank, int m)
{
    int low = 1, high = INT_MIN;
	
	for(int i = 0; i < rank.size(); i++)
		high = max(high, rank[i]*(m*(m+1)/2));
	
	int ans = 0;
		
	while(low <= high)
	{
		int mid = low + (high -low)/2;
		if(valid(mid, rank, m, rank.size()))
		{
			ans = mid;
			high = mid-1;
		}
		else 
			low = mid + 1;
	}
    return ans;
}
	
