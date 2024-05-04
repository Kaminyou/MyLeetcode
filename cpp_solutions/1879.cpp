class Solution {
public:
    int dp(vector<vector<int>>& memo, int state, int n, int currPos, vector<int>& nums1, vector<int>& nums2) {
        if (currPos == n) return 0;
        if (memo[state][currPos] != -1) return memo[state][currPos];
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if ((state & (1 << i)) == 0) {
                res = min(res, (nums2[i] ^ nums1[currPos]) + dp(memo, (state | (1 << i)), n, currPos + 1, nums1, nums2));
            }
        }
        return memo[state][currPos] = res;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<vector<int>> memo((1<<n), vector<int>(n + 1, -1));
        return dp(memo, 0, n, 0, nums1, nums2);
    }
};