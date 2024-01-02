bool isPossible(vector<int> arr, int n, int m, int mid) {
    int painter = 1;
    int boardLength = 0;    
    for(int i = 0; i<m; i++) {
        if(boardLength + arr[i] <= mid) {
            boardLength += arr[i];
        }
        else
        {
            painter++;
            if(painter > n || arr[i] > mid ) {
            return false;
        }
            boardLength = arr[i];
        }
        if(painter > n) {
            return false;
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{

	int s = 0;
    int sum = 0;
    
    for(int i = 0; i<boards.size(); i++) {
        sum += boards[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {

        if(isPossible(boards,k,boards.size(),mid)) {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
