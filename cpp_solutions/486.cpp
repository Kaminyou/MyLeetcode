class Solution {
public:
    int dp(int left, int right, vector<int>& nums, vector<vector<int>>& memo) {
        if (left == right) return nums[left];
        if (memo[left][right] != -1) return memo[left][right];
        return memo[left][right] = max(nums[left] - dp(left + 1, right, nums, memo), nums[right] - dp(left, right - 1, nums, memo));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dp(0, n - 1, nums, memo) >= 0;
    }
};