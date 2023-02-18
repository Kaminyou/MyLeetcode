class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            int end = n - (3 - i);
            ans = min(ans, nums[end] - nums[i]);
        }
        return ans;
    }
};
