class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[n - 1] - nums[0];
        for (int i = 0; i < n - 1; ++i) {
            int minVal = min(nums[0] + k, nums[i + 1] - k);
            int maxVal = max(nums[n - 1] - k, nums[i] + k);
            res = min(res, maxVal - minVal);
        }
        return res;
    }
};
