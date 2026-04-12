class Solution {
public:
    int wordDist(int a, int b) {
        int aX = a / 6;
        int aY = a % 6;
        int bX = b / 6;
        int bY = b % 6;
        return abs(aX - bX) + abs(aY - bY);
    }
    int minimumDistance(string word) {
        int dp[301][26][26];
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                dp[0][i][j] = 0;
            }
        }

        int n = word.size();
        for (int k = 0; k < n; ++k) {
            int w = word[k] - 'A';
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    dp[k + 1][i][j] = INT_MAX / 2;
                }
            }
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    dp[k + 1][i][w] = min(dp[k + 1][i][w], dp[k][i][j] + wordDist(w, j));
                    dp[k + 1][w][j] = min(dp[k + 1][w][j], dp[k][i][j] + wordDist(w, i));
                }
            }
        }
        int res = INT_MAX;
        int w = word[n - 1] - 'A';
        for (int i = 0; i < 26; ++i) {
            res = min(res, dp[n][i][w]);
        }
        for (int j = 0; j < 26; ++j) {
            res = min(res, dp[n][w][j]);
        }
        return res;
    }
};


