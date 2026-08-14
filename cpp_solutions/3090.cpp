class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> counts(26, 0);
        int left = 0;
        int res = 0;
        for (int right = 0; right < n; ++right) {
            counts[s[right] - 'a']++;
            while (left <= right && counts[s[right] - 'a'] > 2) {
                counts[s[left] - 'a']--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
