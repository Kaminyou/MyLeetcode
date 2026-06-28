class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int currMax = 0;
        for (int i = 0; i < n; ++i) {
            currMax = min(currMax + 1, arr[i]);
        }
        return currMax;
    }
};
