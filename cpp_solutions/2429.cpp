class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2);
        vector<bool> binary(32, false);
        int res = 0;
        int index = 31;
        while (num1) {
            if (num1 & 1) binary[index] = true;
            num1 >>= 1;
            index--;
        }
        for (int i = 0; i < 32; ++i) {
            if (count > 0 && binary[i]) {
                res += (1 << (31 - i));
                count--;
            }
        }
        for (int i = 31; i >= 0; --i) {
            if (count > 0 && !binary[i]) {
                res += (1 << (31 - i));
                count--;
            }
        }
        return res;
    }
};

