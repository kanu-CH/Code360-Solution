int minimumJumps(vector<int> &arr, int n)
{
    if (n <= 1) return 0;  // No jumps needed if there's only one shop.
    if (arr[0] == 0) return -1;  // If the first shop can't jump anywhere, it's impossible to reach the end.

    int jumps = 0, farthest = 0, current_end = 0;

    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + arr[i]);  // Track the farthest we can reach from here.
        
        if (i == current_end) {  // If we've reached the current end, we must make a jump.
            jumps++;
            current_end = farthest;
            if (current_end >= n - 1) return jumps;  // If we can reach or exceed the last shop, return the number of jumps.
        }
    }
    
    return -1;  // If we never reach the end, return -1.
}
