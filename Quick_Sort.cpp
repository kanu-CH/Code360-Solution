#include <bits/stdc++.h> 
int partition (vector<int>& arr, int l, int r)
{
    int x = arr[r];
    int i = l - 1;
    for (int j = l; j <= r- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}
 
void qSort(vector<int>& arr, int l, int r)
{
    if (l < r)
    {
        int q = partition(arr, l,r);
        qSort(arr, l, q - 1);
        qSort(arr, q + 1, r);
    }
}
vector<int> quickSort(vector<int> arr)
{
    qSort(arr,0,arr.size()-1);
    return arr;
}
