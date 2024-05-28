class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(s[i] - t[i]);
        }

        int curr = 0;
        int left = 0;
        int res = 0;
        for (int right = 0; right < n; ++right) {
            curr += diff[right];
            while (curr > maxCost) {
                curr -= diff[left];
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
