class Solution {
public:
    const int mod = 1337;
    int power(int x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x % mod;
        return power(x, n / 2) * power(x, n - n / 2) % mod;
    }
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int i = 0; i < b.size(); ++i) {
            res = power(res, 10) * power(a, b[i]) % mod;
        }
        return res;
    }
};