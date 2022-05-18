class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int n = s.size();
        int res = 0;
        int left = 0;
        // valid interval:
        // interval length - len of max element <= k
        // if > k => left++
        for (int right = 0; right < n; ++right) {
            counts[s[right] - 'A']++;
            while (right - left + 1 - *max_element(counts.begin(), counts.end()) > k) {
                counts[s[left] - 'A']--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};