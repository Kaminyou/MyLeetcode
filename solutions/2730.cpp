class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        if (s.size() == 1) return 1;
        int left = 0;
        int n = s.size() - 1;
        int res = 2;
        bool theSame = false;
        for (int right = 1; right <= n; ++right) {
            if (s[right] == s[right - 1]) {
                while (theSame) {
                    if (s[left] == s[left + 1]) theSame = false;
                    left++;
                }
                theSame = true;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};