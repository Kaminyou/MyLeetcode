class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool negative = false;
        if (num < 0) negative = true;
        num = abs(num);
        string res;
        while (num) {
            res.push_back((num % 7) + '0');
            num /= 7;
        }
        reverse(res.begin(), res.end());
        
        if (negative) res = "-" + res;
        return res;
    }
};