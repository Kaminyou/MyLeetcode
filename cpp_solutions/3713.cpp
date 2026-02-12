class Solution {
public:
    bool valid(int* hash) {
        int x = 0;
        for (int i = 0; i < 26; ++i) {
            if (hash[i] != 0) {
                if (x == 0) x = hash[i];
                else if (hash[i] != x) return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int hash[26];
        int n = s.size();
        int res = 0;
        for (int start = 0; start < n; ++start) {
            for (int i = 0; i < 26; ++i) hash[i] = 0;
            for (int end = start; end < n; ++end) {
                hash[s[end] - 'a']++;
                if (valid(hash)) res = max(res, end - start + 1);
            }
        }
        return res;
    }
};
