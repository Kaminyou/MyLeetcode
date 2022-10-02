class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        int m = numSlots;
        
        vector<vector<int>> dp(n + 1, vector<int>(pow(3, m), -INT_MAX / 2));
        dp[0][0] = 0;
        
        int res = 0;
        for (int state = 1; state < pow(3, m); ++state) {
            int i = 0;
            int temp = state;
            while (temp) {
                i += temp % 3;
                temp /= 3;
            }
            if (i > n) continue;
            
            for (int j = 0; j < m; ++j) {
                if (findBit(state, j) >= 1) {
                    dp[i][state] = max(dp[i][state], dp[i - 1][state - pow(3, j)] + (nums[i] & (j + 1)));
                }
            }
            if (i == n) {
                res = max(res, dp[i][state]);
            }
        }
        return res;
    }
    int findBit(int state, int j) {
        for (int i = 0; i < j; ++i) state /= 3;
        return state % 3;
    }
};