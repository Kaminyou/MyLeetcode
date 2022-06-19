class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        int res = -1;
        for (int i = 1; i <= 10; ++i) {
            int temp = k * i;
            if ((temp % 10) == (num % 10)) {
                res = i;
                break;
            }
        }
        if (k * res > num) return -1;
        return res;
    }
};