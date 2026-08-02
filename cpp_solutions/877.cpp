class Solution {
public:
    int dp(int left, int right, vector<int>& nums, vector<vector<int>>& memo) {
        if (left == right) return nums[left];
        if (memo[left][right]) return memo[left][right];
        return memo[left][right] = max(nums[left] - dp(left + 1, right, nums, memo), nums[right] - dp(left, right - 1, nums, memo));
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        return dp(0, n - 1, piles, memo) >= 0;
    }
};
