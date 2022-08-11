class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(3, false));
        if (n == 2) {
            if (nums[0] == nums[1]) return true;
            else return false;
        }
                
        if (nums[0] == nums[1]) dp[1][0] = true;
        if ((nums[0] == nums[1]) && (nums[1] == nums[2])) dp[2][1] = true;
        if ((nums[1] - nums[0] == 1) && (nums[2] - nums[1] == 1)) dp[2][2] = true;
        
        for (int i = 3; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (nums[i] == nums[i - 1]) {
                    if (dp[i - 2][j]) dp[i][0] = true;
                }
                if ((nums[i] == nums[i - 1]) && (nums[i - 1] == nums[i - 2])) {
                    if (dp[i - 3][j]) dp[i][1] = true;
                }
                if ((nums[i] - nums[i - 1] == 1) && (nums[i - 1] - nums[i - 2] == 1)) {
                    if (dp[i - 3][j]) dp[i][2] = true;
                }
            }
        }
        
        for (int i = 0; i < 3; ++i) {
            if (dp[n - 1][i]) return true;
        }
        return false;
    }
};