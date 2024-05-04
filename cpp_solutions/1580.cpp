class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = warehouse[0];
        right[n - 1] = warehouse[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = min(left[i - 1], warehouse[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            right[i] = min(right[i + 1], warehouse[i]);
        }
        
        vector<int> heights(n, 0);
        for (int i = 0; i < n; ++i) heights[i] = max(left[i], right[i]);
        
        sort(boxes.begin(), boxes.end());
        sort(heights.begin(), heights.end());
        
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (heights[i] >= boxes[index]) {
                index++;
            }
            if (index == boxes.size()) break;
        }
        return index;
    }
};