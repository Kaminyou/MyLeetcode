class Solution {
public:
    int dfs(vector<int>& boxes, int left, int right, int k, int dp[100][100][100]) {
        if (left > right) return 0;
        if (dp[left][right][k] > 0) return dp[left][right][k];
        dp[left][right][k] = dfs(boxes, left + 1, right, 0, dp) + (k + 1) * (k + 1);
        for (int i = left + 1; i <= right; i++) {
            if (boxes[left] == boxes[i]) {
                // XABCXDEF => ABC + XXDEF
                dp[left][right][k] = max(dp[left][right][k], dfs(boxes, left + 1, i - 1, 0, dp) + dfs(boxes, i, right, k + 1, dp));
            }
        }
        return dp[left][right][k];
    }
    int removeBoxes(vector<int>& boxes) {
        // left, right, # of same num to the left
        int dp[100][100][100] = {0};
        return dfs(boxes, 0, boxes.size() - 1, 0, dp);
    }
};