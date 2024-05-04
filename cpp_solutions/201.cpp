class Solution {
public:
    vector<bool> num2bits(int num) {
        vector<bool> bits(32, 0);
        int index = 31;
        while (num) {
            bits[index] = num % 2;
            num /= 2;
            index--;
        }
        return bits;
    }
    int rangeBitwiseAnd(int left, int right) {
        vector<bool> leftBits = num2bits(left);
        vector<bool> rightBits = num2bits(right);
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (!leftBits[i] && !rightBits[i]) continue;
            else if (leftBits[i] && rightBits[i]) {
                res += (1 << (32 - i - 1));
            }
            else break;
        }
        return res;
    }
};