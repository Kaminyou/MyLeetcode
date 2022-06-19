class Solution {
public:
    int longestSubsequence(string s, int k) {
        int val = 0;
        int count = 0;
        int pow = 1;
        for (int i = s.size() - 1; i >= 0 && val + pow <= k; --i) {
            if (s[i] == '1') {
                count++;
                val += pow;
            }
            pow <<= 1;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') count++;
        }
        return count;
    }
};