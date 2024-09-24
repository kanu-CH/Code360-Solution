#include <bits/stdc++.h>
/*
    The higherlower(int n) function can be called from guesser object
    @api: guesser.higherlower(n)
    return value will be -1 if n is lower, 0 is n is equal or 1 if n is higher.
*/

int numberGuess(int n, Guesser guesser){
    int low = 0, high = n;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate mid to avoid overflow
        
        int result = guesser.higherlower(mid); 
        
        if (result == 0) {
            return mid; // Correct guess
        } else if (result == 1) {
            high = mid - 1; // The hidden number is smaller
        } else {
            low = mid + 1; // The hidden number is larger
        }
    }
    
    return -1;
}
