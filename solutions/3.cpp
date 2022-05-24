class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, 0);
        int n = s.size();
        int res = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            char c = s[right];
            while (hash[c] >= 1) {
                char _c = s[left];
                hash[_c]--;
                left++;
            }
            hash[c]++;
            res = max(res, right - left + 1);
        }
        return res;
    }
};