class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int index = 0;
        int res = 0;
        while (index < n) {
            int start = index;
            int current = s[index];
            while (index + 1 < n && s[index + 1] - current == 1) {
                index++;
                current++;
            }
            res = max(res, index - start + 1);
            index++;
        }
        return res;
    }
};