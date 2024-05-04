class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordHash;
        for (auto word : wordDict) wordHash.insert(word);
        
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                bool exist = (wordHash.find(s.substr(j, i - j)) != wordHash.end());
                if (dp[j] && exist) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};