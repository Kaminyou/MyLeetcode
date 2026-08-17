class Solution {
public:
    int dp(int left, int right, vector<int>& stoneValue, vector<vector<int>>& memo) {
        if (left == right) return 0;
        if (memo[left][right] != -1) return memo[left][right];
        int rightSum = 0;
        for (int i = left; i <= right; ++i) rightSum += stoneValue[i];
        int leftSum = 0;
        int res = 0;
        for (int i = left; i < right; ++i) {
            leftSum += stoneValue[i];
            rightSum -= stoneValue[i];
            if (leftSum > rightSum) {
                res = max(res, rightSum + dp(i + 1, right, stoneValue, memo));
            }
            else if (leftSum < rightSum) {
                res = max(res, leftSum + dp(left, i, stoneValue, memo));
            }
            else {
                res = max(res, leftSum + dp(left, i, stoneValue, memo));
                res = max(res, rightSum + dp(i + 1, right, stoneValue, memo));
            }
        }
        return memo[left][right] = res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dp(0, n - 1, stoneValue, memo);
    }
};
