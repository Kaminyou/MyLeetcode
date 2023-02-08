class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int step = nums[i];
            for (int j = 1; j <= step; ++j) {
                if (i + j >= n) break;
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[n - 1];
    }
};

//v2
class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0;
        int farthest = 0;
        int steps = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > near) {
                steps++;
                near = farthest;
            }
            farthest = max(farthest, i + nums[i]);
        }
        return steps;
    }
};