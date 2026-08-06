class Solution {
public:
    int prod(int num) {
        int res = 1;
        while (num) {
            int digit = num % 10;
            num /= 10;
            res *= digit;
        }
        return res;
    }
    int smallestNumber(int n, int t) {
        for (int i = 0; i < 10; ++i) {
            if (prod(n + i) % t == 0) return n + i;
        }
        return -1;
    }
};
