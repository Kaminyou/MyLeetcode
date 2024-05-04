class Solution {
public:
    vector<vector<int>> memo;
    int cntLength(int x) {
        if (x == 1) return 0;
        if (x < 10) return 1;
        if (x < 100) return 2;
        return 3;
    }
    int dp(string& s, int n, int index, int k) {
        if (k < 0) return INT_MAX / 2;
        if (index >= n) return 0;
        if (index + k >= n) return 0;
        if (memo[index][k] != -1) return memo[index][k];
        int res = INT_MAX / 2;
        vector<int> charCnt(26, 0);
        int most = 0;
        for (int j = index; j < n; ++j) {
            charCnt[s[j] - 'a']++;
            most = max(most, charCnt[s[j] - 'a']);
            res = min(res, 1 + cntLength(most) + dp(s, n, j + 1, k - (j - index + 1 - most)));
        }
        return memo[index][k] = res;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        memo.resize(n + 1, vector<int>(n + 1, -1));
        return dp(s, n, 0, k);
    }
};
