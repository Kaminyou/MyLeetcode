class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int carry = 0;
        int res = 0;
        for (int i = n - 1; i > 0; --i) {
            res += 1;
            if (s[i] - '0' + carry == 1) {
                carry = 1;
                res += 1;
            }
        }
        return res + carry;
    }
};
