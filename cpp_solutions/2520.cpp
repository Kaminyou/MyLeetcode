class Solution {
public:
    int countDigits(int num) {
        int cnt = 0;
        int temp = num;
        while (num) {
            int digit = num % 10;
            num /= 10;
            if (temp % digit == 0) cnt++;
        }
        return cnt;
    }
};