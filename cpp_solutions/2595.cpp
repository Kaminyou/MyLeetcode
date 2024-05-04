class Solution {
public:
    vector<int> evenOddBit(int n) {
        bool even = true;
        int evenCnt = 0;
        int oddCnt = 0;
        while (n) {
            if (even) {
                evenCnt += n & 1;
            }
            else {
                oddCnt += n & 1;
            }
            n /= 2;
            even ^= 1;
        }
        return {evenCnt, oddCnt};
    }
};