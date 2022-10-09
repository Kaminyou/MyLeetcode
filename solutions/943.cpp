class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0)); // i -> j
        vector<vector<string>> dp(1 << n, vector<string>(n));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int minLen = min(words[i].size(), words[j].size());
                for (int k = minLen - 1; k >= 0; --k) {
                    if (words[i].substr(words[i].size() - k) == words[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            dp[1 << i][i] = words[i];
        }
        for (int state = 1; state < (1 << n); ++state) {
            for (int j = 0; j < n; ++j) {
                if ((state & (1 << j)) == 0) continue;
                for (int i = 0; i < n; ++i) {
                    if (i == j || (state & (1 << i)) == 0) continue;
                    string temp = dp[state ^ (1 << j)][i] + words[j].substr(overlap[i][j]);
                    if (dp[state][j].size() == 0 || temp.size() < dp[state][j].size()) {
                        dp[state][j] = temp;
                    }
                }
            }
        }
        
        int lastState = (1 << n) - 1;
        string res = dp[lastState][0];
        for (int i = 0; i < n; ++i) {
            if (dp[lastState][i].size() < res.size()) {
                res = dp[lastState][i];
            }
        }
        return res;
    }
};