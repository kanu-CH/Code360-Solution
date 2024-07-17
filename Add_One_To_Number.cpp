#include <bits/stdc++.h> 
vector<int> addOneToNumber(vector<int> arr)
{
    int n = arr.size();
    for(int i = n-1; i >= 0; i--){
        if(i == n-1)
            arr[i]++;
        if(arr[i] == 10){
            arr[i] = 0;
            if(i != 0){
                arr[i-1]++;
            }
            else{
                arr.push_back(0);
                arr[i] = 1;
            }
        }
    }
    while (arr.size() > 1 && arr[0] == 0) {
        arr.erase(arr.begin());
    }
    return arr;
}
