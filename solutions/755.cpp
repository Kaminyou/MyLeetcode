class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        int n = heights.size();
        while (volume) {
            int left = k;
            int leftIdx = k;
            int leftValue = heights[k];
            int right = k;
            int rightIdx = k;
            int rightValue = heights[k];
            bool flag = false;
            while (left - 1 >= 0 && heights[left - 1] <= heights[left]) {
                if (heights[left - 1] < leftValue) {
                    leftValue = heights[left - 1];
                    leftIdx = left - 1;
                }
                left--;
            }
            if (leftIdx != k) {
                heights[leftIdx]++;
                flag = true;
            }
            while (!flag && right + 1 < n && heights[right + 1] <= heights[right]) {
                if (heights[right + 1] < rightValue) {
                    rightValue = heights[right + 1];
                    rightIdx = right + 1;
                }
                right++;
            }
            if (rightIdx != k) {
                heights[rightIdx]++;
                flag = true;
            }
            if (!flag) {
                heights[k]++;
            }
            volume--;
        }
        return heights;
    }
};