class Solution {
public:
    int length = 0;
    string out;
    void expend(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > length) {
                length = right - left + 1;
                out = s.substr(left, right - left + 1);
            }
            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            expend(s, i, i);
            expend(s, i, i + 1);
        }
        return out;
    }
};