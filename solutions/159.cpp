class Solution {
public:
    int char2idx(const char& c) {
        if (c >= 'a' && c <= 'z') return c - 'a';
        else return c - 'A' + 26;
    }
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> counting(52, 0);
        int count = 0;
        int res = 1;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (counting[char2idx(s[right])] == 0) count++;
            counting[char2idx(s[right])]++;
            while (count > 2) {
                if (counting[char2idx(s[left])] == 1) count--;
                counting[char2idx(s[left])]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};