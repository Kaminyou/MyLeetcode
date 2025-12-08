class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                int c = (int)(sqrt(a * a + b * b));
                if (c > n) continue;
                if (a * a + b * b == c * c) {
                    res++;
                }
            }
        }
        return res;
    }
};

