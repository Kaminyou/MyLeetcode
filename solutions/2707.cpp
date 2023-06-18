class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<vector<bool>> matchMap(n, vector<bool>(n + 1, false));
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i + j <= n; ++j) {
                string substring = s.substr(i, j);
                if (st.count(substring)) matchMap[i][j] = true;
            }
        }
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i] + 1;
            for (int j = 1; i + 1 - j >= 0; ++j) {
                if (matchMap[i + 1 - j][j]) {
                    dp[i + 1] = min(dp[i + 1], dp[i + 1 - j]);
                };
            }
        }
        return dp[n];
    }
};