class Solution {
public:
    int commonFactors(int a, int b) {
        int gcd = __gcd(a, b);
        int cnt = 0;
        for (int i = 1; i <= gcd; ++i) {
            if (gcd % i == 0) cnt++;
        }
        return cnt;
    }
};