class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int dp[1001][1001]; // prev; curr
        int temp[1001];
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                dp[i][j] = 0;
            }
        }

        for (int j = 0; j < k; ++j) {
            dp[j][nums[0] % k] = 1;
        }

        for (int i = 1; i < n; ++i) {
            int curr = nums[i] % k;
            for (int j = 0; j < k; ++j) {
                temp[j] = dp[curr][j];
            }
            for (int j = 0; j < k; ++j) {
                dp[j][curr] = temp[j] + 1;
                res = max(res, dp[j][curr]);
            }
        }
        return res;
    }
};

