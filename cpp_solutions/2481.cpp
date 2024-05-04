class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) return 0;
        if (n & 1) return n;
        else return n / 2;
    }
};
