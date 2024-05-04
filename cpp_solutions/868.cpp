class Solution {
public:
    int binaryGap(int n) {
        int left = -1;
        int right = -1;
        int res = 0;
        int index = 0;
        while (n) {
            int digit = n & 1;
            if (digit) {
                if (left == -1) left = index;
                else {
                    right = left;
                    left = index;
                }
                if (right != -1) res = max(res, left - right);
            }
            index++;
            n >>= 1;
        }
        return res;
    }
};