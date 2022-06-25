class Solution {
public:
    int dp(int i, int j, vector<vector<int>>& memo, vector<int>& prefix) {
        if (i + 2 * j >= prefix.size()) return prefix[i];
        if (memo[i][j] != -1) return memo[i][j];
        for (int k = 1; k <= 2 * j; ++k) {
            memo[i][j] = max(memo[i][j], prefix[i] - dp(i + k, max(k, j), memo, prefix));
        }
        return memo[i][j];
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> prefix = piles;
        vector<vector<int>> memo(n, vector<int>(n, -1));
        for (int i = n - 2; i >= 0; --i) {
            prefix[i] += prefix[i + 1];
        }
        return dp(0, 1, memo, prefix);
    }
};

// class Solution {
// public:
//     int dp(vector<int>& piles, vector<vector<int>>& memo, int curr, int m) {
//         if (curr >= piles.size()) return 0;
//         if (memo[curr][m] != INT_MIN) return memo[curr][m];
//         int sum = 0;
//         int res = INT_MIN;
//         for (int i = 0; i < 2 * m && curr + i < piles.size(); ++i) {
//             sum += piles[curr + i];
//             res = max(res, sum - dp(piles, memo, curr + i + 1, max(m, i + 1)));
//         }
//         return memo[curr][m] = res;
//     }
//     int stoneGameII(vector<int>& piles) {
//         int n = piles.size();
//         vector<vector<int>> memo(n, vector<int>(n + 1, INT_MIN));
//         // alice - bob = ans
//         // alice + bob = sum
//         // alice = (ans + sum) / 2
//         int ans = dp(piles, memo, 0, 1);
//         int sum = 0;
//         for (auto& pile : piles) sum += pile;
//         return (ans + sum) / 2;
//     }
// };