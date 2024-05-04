class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while (n) {
            int digit = n % 10;
            n /= 10;
            product *= digit;
            sum += digit;
        }
        return product - sum;
    }
};