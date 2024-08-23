#include <bits/stdc++.h>

struct Box {
    int h, w, l;
};

int findMaxHeight(vector<int> &height, vector<int> &width, vector<int> &length, int n) {
    vector<Box> boxes;

    // Generate all rotations of the boxes
    for (int i = 0; i < n; i++) {
        int h = height[i], w = width[i], l = length[i];
        boxes.push_back({h, min(w, l), max(w, l)});
        boxes.push_back({w, min(h, l), max(h, l)});
        boxes.push_back({l, min(h, w), max(h, w)});
    }

    // Sort the boxes based on base area (width * length) in descending order
    sort(boxes.begin(), boxes.end(), [](Box a, Box b) {
        return (a.w * a.l) > (b.w * b.l);
    });

    int m = boxes.size();
    vector<int> maxHeight(m);

    // Initialize each box's height as the maxHeight when it's the only box
    for (int i = 0; i < m; i++) {
        maxHeight[i] = boxes[i].h;
    }

    // Apply the LIS-based approach
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (boxes[i].w < boxes[j].w && boxes[i].l < boxes[j].l) {
                maxHeight[i] = max(maxHeight[i], maxHeight[j] + boxes[i].h);
            }
        }
    }

    // The maximum value in maxHeight is the height of the tallest stack
    return *max_element(maxHeight.begin(), maxHeight.end());
}
