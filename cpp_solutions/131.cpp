class Solution {
public:
    vector<vector<string>> res;
    void backtracking(int index, vector<string>& path, string& s, vector<vector<bool>>& dp) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (dp[index][i]) {
                path.push_back(s.substr(index, i - index + 1));
                backtracking(i + 1, path, s, dp);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false)); // s[i : j] is palindrome or not
        for (int i = 0; i < n; ++i) dp[i][i] = true;
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i < n; ++i) {
                int j = i + length - 1;
                if (j > n) break;
                if (length == 2) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (dp[i + 1][j - 1] && (s[i] == s[j]));
                }
            }
        }

        vector<string> path;
        backtracking(0, path, s, dp);
        return res;
    }
};