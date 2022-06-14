class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0;
        int unique = 0;
        vector<int> counts(256, 0);
        int res = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (counts[s[right]] == 0) unique++;
            counts[s[right]]++;
            while (unique > k) {
                if (counts[s[left]] == 1) unique--;
                counts[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};