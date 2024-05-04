class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> suffix(n, 0);
        suffix[0] = 0;
        
        for (int i = 1; i < n; ++i) {
            int j = suffix[i - 1];
            while (j >= 1 && s[i] != s[j]) {
                j = suffix[j - 1];
            }
            suffix[i] = j + (s[i] == s[j]);
        }
        
        int length = suffix[n - 1];
        return s.substr(0, length);
    }
};