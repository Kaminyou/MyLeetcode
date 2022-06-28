class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n, ""));
        for (int length = 1; length <= n; ++length) {
            for (int left = 0; left + length - 1 < n; ++left) {
                int right = left + length - 1;
                dp[left][right] = s.substr(left, length);
                
                // check if s[l, r] can be composed by substring
                string temp = s.substr(left, length);
                int idx = (temp + temp).find(temp, 1);
                if (idx < temp.size()) {
                    int count = temp.size() / idx;
                    string compose = to_string(count) + "[" + dp[left][left + idx - 1] + "]";
                    if (compose.size() < temp.size()) {
                        dp[left][right] = compose;
                        continue;
                    }
                }
                // split s[l,r] to s[l, k] + s[k+1, r]
                for (int k = left; k < right; ++k) {
                    string combine = dp[left][k] + dp[k + 1][right];
                    if (combine.size() < dp[left][right].size()) {
                        dp[left][right] = combine;
                    } 
                }
            }
        }
        return dp[0][n - 1];
    }
};