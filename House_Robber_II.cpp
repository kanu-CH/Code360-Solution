#include <limits.h>

long long int solve3(vector<int> &nums,int start,int end)
{
    int n = nums.size();
    long long int  prev2 =nums[start] ;
    long long int  prev1 = max(nums[start],nums[start+1]);

    for(int i =start+2;i<=end;i++)
    {
        long long int include = prev2+nums[i];
        long long int exclude = prev1;
        long long int ans = max(include,exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n==1)
    {
        return valueInHouse[0];
    }
    return max(solve3(valueInHouse,0,n-2),solve3(valueInHouse,1,n-1));
}
