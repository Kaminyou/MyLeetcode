class Solution {
public:
    vector<int> getSuffix(string& p) {
        int n = p.size();
        vector<int> suffix(n, 0);
        suffix[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = suffix[i - 1];
            while (j >= 1 && p[i] != p[j]) {
                j = suffix[j - 1];
            }
            suffix[i] = j + (p[i] == p[j]);
        }
        return suffix;
    }
    string shortestPalindrome(string s) {
        // B + s: BAA'B'
        // => s: AA'B' = pattern
        // => revS: BAA' = target
        // find longest matched pattern in target
        if (s == "") return s;
        string pattern = s;
        string target = s;
        reverse(target.begin(), target.end());
        
        vector<int> suffix = getSuffix(pattern);
        
        int n = target.size();
        vector<int> dp(n, 0);
        dp[0] = target[0] == pattern[0];
        for (int i = 1; i < n; ++i) {
            int j = dp[i - 1];
            while (j >= 1 && target[i] != pattern[j]) {
                j = suffix[j - 1];
            }
            dp[i] = j + (target[i] == pattern[j]);
        }
        
        int length = dp[n - 1];
        string B = s.substr(length);
        reverse(B.begin(), B.end());
        return B + s;
    }
};