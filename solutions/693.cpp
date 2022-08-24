class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long nn = n;
        nn = nn ^ (nn >> 1);
        return (nn & nn + 1) == 0;
    }
};
