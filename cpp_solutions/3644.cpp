class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int smallest = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) smallest = min(smallest, i);
        }
        if (smallest == INT_MAX) return 0;
        int res = smallest;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                res = res & nums[i];
            }
        }
        return res;
    }
};

