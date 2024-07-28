#include <vector>
#include <stack>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	vector<int> nge(n, -1);  // Initialize the result array with -1
    stack<int> s;  // Stack to store indices

    // Traverse the array from the end to the beginning
    for (int i = n - 1; i >= 0; --i) {
        // Pop elements from the stack while stack is not empty and the current element is greater than the stack's top element
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        
        // If stack is not empty, then the top of the stack is the next greater element
        if (!s.empty()) {
            nge[i] = arr[s.top()];
        }

        // Push the current index onto the stack
        s.push(i);
    }

    return nge;
}
