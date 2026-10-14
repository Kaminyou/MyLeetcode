class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        while (num--) {
            int digit = min(9, sum);
            sum -= digit;
            res.push_back(digit + '0');
        }
        if (sum) return "";
        return res;
    }
};

