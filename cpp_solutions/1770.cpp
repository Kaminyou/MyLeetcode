class Solution {
public:
    int N;
    int M;
    int dp(int l, int cnt, vector<int>& nums, vector<int>& multipliers, vector<vector<int>>& memo) {
        if (cnt == M) return 0;
        if (memo[l][cnt] != INT_MIN) return memo[l][cnt];
        int pickLeft = dp(l + 1, cnt + 1, nums, multipliers, memo) + nums[l] * multipliers[cnt];
        int pickRight = dp(l, cnt + 1, nums, multipliers, memo) + nums[N - 1 - (cnt - l)] * multipliers[cnt];
        return memo[l][cnt] = max(pickLeft, pickRight);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        N = nums.size();
        M = multipliers.size();
        vector<vector<int>> memo(M + 1, vector<int>(M + 1, INT_MIN));
        return dp(0, 0, nums, multipliers, memo);
    }
};