class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hex = "0123456789abcdef";
        string res;
        int count = 0;
        while (num && count < 8) {
            char c = hex[(num & 0xf)];
            res.push_back(c);
            num >>= 4;
            count++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};