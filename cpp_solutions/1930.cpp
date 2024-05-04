class Solution {
public:
    int countSub(string& s, char target) {
        int first = INT_MAX;
        int last = INT_MIN;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == target) {
                first = min(first, i);
                last = max(last, i);
            }
        }
        if (first == last) return 0;
        if (first == INT_MAX) return 0;
        vector<bool> hash(26, false);
        for (int i = first + 1; i <= last - 1; ++i) {
            hash[s[i] - 'a'] = true;
        }
        int cnt = 0;
        for (int i = 0; i < 26; ++i) cnt += hash[i];
        return cnt;
    }
    int countPalindromicSubsequence(string s) {
        int cnt = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            cnt += countSub(s, c);
        }
        return cnt;
    }
};
