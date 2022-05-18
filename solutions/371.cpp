class Solution {
public:
    int getSum(int a, int b) {
        int sum, carry;
        while (b) {
            sum = a ^ b;
            carry = (a & b & 0x7fffffff) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};