#include <algorithm>

class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int curr_size;
    Kthlargest(int k, vector<int> &arr) {
        curr_size = k;
        for (auto& x : arr) {
            pq.push(x);
            if (pq.size() > curr_size) {
                pq.pop();
            }
        }
    }

    int add(int num) {
        pq.push(num);
        if (pq.size() > curr_size) {
            pq.pop();
        }
        return pq.top();
    }

};
