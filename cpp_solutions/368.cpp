class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 1;
        int currIdx = -1;
        vector<int> dp(n, 1);
        vector<int> path(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        path[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }
                if (dp[i] > res) {
                    res = dp[i];
                    currIdx = i;
                }
            }
        }
        vector<int> ans;
        if (res == 1) {
            ans.push_back(nums[0]);
            return ans;
        }
        for (int i = 0; i < res; i++) {
            ans.push_back(nums[currIdx]);
            currIdx = path[currIdx];
        }
        //reverse(ans.begin(), ans.end());
        return ans;
    }
};