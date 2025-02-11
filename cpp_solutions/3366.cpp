class Solution {
public:
    int dp(vector<int>& nums, int index, int k, int op1, int op2, vector<vector<vector<int>>>& memo) {
        if (index == nums.size()) return 0;
        if (memo[index][op1][op2] != -1) return memo[index][op1][op2];
        int minVal = nums[index] + dp(nums, index + 1, k, op1, op2, memo);
        if (op1 > 0) minVal = min(minVal, (nums[index] - 1) / 2 + 1 + dp(nums, index + 1, k, op1 - 1, op2, memo));
        if (op2 > 0 && nums[index] >= k) minVal = min(minVal, nums[index] - k + dp(nums, index + 1, k, op1, op2 - 1, memo));
        if (op1 > 0 && op2 > 0 && nums[index] >= k) {
            if ((nums[index] - 1) / 2 + 1 >= k) minVal = min(minVal, (nums[index] - 1) / 2 + 1 - k + dp(nums, index + 1, k, op1 - 1, op2 - 1, memo));
            minVal = min(minVal, (nums[index] - k - 1) / 2 + 1 + dp(nums, index + 1, k, op1 - 1, op2 - 1, memo));
        }
        return memo[index][op1][op2] = minVal;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return dp(nums, 0, k, op1, op2, memo);
    }
};
