#include <bits/stdc++.h>
class node{
    public:
        int data;
        int row;
        int col;
        node(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }
};
class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> minHeap;
    
    //storing starting element of each list and tracking min and max value
    for(int i=0; i<k; i++){
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }
    
    int start = mini, end = maxi;

    //process range
    while(!minHeap.empty()){
        node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;

        //range updation
        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }        

        //next element exist
        if(temp->col+1 < n){
            maxi = max(maxi, a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1], temp->row, temp->col+1));
        }
        else
            break;
    }
    return end-start+1;
}
