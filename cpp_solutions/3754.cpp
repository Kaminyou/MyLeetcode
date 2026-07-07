class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long factor = 1;
        long long sum = 0;
        while (n) {
            int digit = n % 10;
            n /= 10;
            sum += digit;
            if (digit != 0) {
                num += digit * factor;
                factor *= 10;
            }
        }
        return sum * num;
    }
};
