class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            int pop = x % 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8)) return 0;
            res = res * 10 + pop;
            x /= 10;
        }
        return res;
    }
};