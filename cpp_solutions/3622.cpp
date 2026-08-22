class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int tmp = n;
        while (n) {
            int digit = n % 10;
            n /= 10;
            sum += digit;
            prod *= digit;
        }
        return (tmp % (sum + prod)) == 0;
    }
};
