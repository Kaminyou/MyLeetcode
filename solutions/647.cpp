class Solution {
public:
    int count = 0;
    void check(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); i++) {
            check(s, i, i);
            check(s, i, i + 1);
        }
        return count;
    }
};