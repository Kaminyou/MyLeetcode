class Solution {
public:
    int passThePillow(int n, int time) {
        int mod = 2 * n - 2;
        int residual = time % mod;
        if (residual >= n) residual = mod - residual;
        return residual + 1;
    }
};

