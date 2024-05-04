class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int n = p.size();
        int length = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && (p[i] == p[i - 1] + 1 || p[i] == p[i - 1] - 25)) {
                length++;
            }
            else length = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], length);
        }
        int res = 0;
        for (auto num : dp) res += num;
        return res;
    }
};