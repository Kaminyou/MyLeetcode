class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1 || k == 1) return 0;
        
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 0; i < n - k + 1; i++) {
            res = min(res, nums[i + k - 1] - nums[i]);
        }
        return res;
    }
};