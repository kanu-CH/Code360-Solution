#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> res;
    for(int col=0; col<mCols; col++){
        if(col&1){
          for(int row = nRows-1; row>=0; row--) {
                res.push_back(arr[row][col]);
            }   
        }
        else{
          for(int row = 0; row<nRows; row++) {
                res.push_back(arr[row][col]);
            }
        }
    }
    return res;
}
