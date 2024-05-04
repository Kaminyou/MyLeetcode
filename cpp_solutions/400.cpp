class Solution {
public:
    int findNthDigit(int n) {
        int length = 1;
        long long sum = 0;
        while (sum + length * 9 * pow(10, length - 1) < n) {
            sum += length * 9 * pow(10, length - 1);
            length++;
        }
        n--;
        long long indexNum = (n - sum) / length;
        long long indexDigit = (n - sum) % length;
        long long num = pow(10, length - 1) + indexNum;
        return to_string(num)[indexDigit] - '0';     
    }
};
// 1-9: 1 * 9
// 10-99: 2 * 90
// 100-999: 3 * 900
// 1000-9999: 4 * 9000