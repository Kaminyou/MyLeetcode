class Solution {
public:
    int longestValidParentheses(string s) {
        int left, right;
        int res = 0;
        left = 0;
        right = 0;
        for (auto c : s) {
            if (c == '(') left++;
            else right++;
            if (left == right) res = max(res, left + right);
            if (right > left) {
                left = right = 0;
            }
        }
        
        left = right = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == '(') left++;
            else right++;
            if (left == right) res = max(res, left + right);
            if (right < left) {
                left = right = 0;
            }
        }
        return res;
    }
};