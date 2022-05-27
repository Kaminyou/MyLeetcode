class Solution {
public:
    bool hasNoDuplicate(int len, const string& s) {
        unordered_set<string> st;
        int n = s.size();
        for (int left = 0, right = len - 1; right < n; ++left, ++right) {
            string temp = s.substr(left, len);
            if (st.find(temp) != st.end()) return false;
            st.insert(temp);
        }
        return true;
    }
    int longestRepeatingSubstring(string s) {
        int left = 0;
        int right = s.size();
        // find the min len let any substr of this len has no duplicate
        // => len - 1 is the answer
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (hasNoDuplicate(mid, s)) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};
// DP version
// class Solution {
// public:
//     int longestRepeatingSubstring(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//         int res = 0;
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j < i; ++j) {
//                 if (s[i - 1] == s[j - 1]) {
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                     res = max(res, dp[i][j]);
//                 }
//             }
//         }
//         return res;
//     }
// };