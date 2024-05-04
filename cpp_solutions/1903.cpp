class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int res = -1;
        for (int i = n - 1; i >= 0; --i) {
            if ((num[i] - '0') & 1) {
                res = i;
                break;
            }
        }
        if (res == -1) return "";
        return num.substr(0, res + 1);
    }
};