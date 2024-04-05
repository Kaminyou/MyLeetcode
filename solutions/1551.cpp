class Solution {
public:
    int minOperations(int n) {
        int residual = -1;
        int cnt = -1;
        int minus = -1;
        if (n & 1) {
            residual = 0;
            cnt = (n + 1) / 2;
            minus = 2;
        }
        else {
            residual = 1;
            cnt = n / 2;
            minus = 1;
        }
        return (residual + (cnt * 2 - minus)) * cnt / 2;
    }
};
// odd
// 0 (1) + 2 (3) + 4 (5) ...
// even
// 1 (2) + 3 (4) + 5 (6) ...
