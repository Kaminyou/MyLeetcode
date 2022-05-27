class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) return 0;
        int len = log2(num) + 1;
        int count = __builtin_popcount(num);
        return len + count - 1;
    }
};