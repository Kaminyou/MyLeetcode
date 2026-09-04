class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixMax(n, -1);
        vector<int> suffixMin(n, INT_MAX);
        int currMax = INT_MIN;
        for (int i = 0; i < n; ++i) {
            currMax = max(currMax, nums[i]);
            prefixMax[i] = currMax;
        }
        int currMin = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            currMin = min(currMin, nums[i]);
            suffixMin[i] = currMin;
        }
        for (int i = 0; i < n; ++i) {
            int stability = prefixMax[i] - suffixMin[i];
            if (stability <= k) return i;
        }
        return -1;
    }
};

