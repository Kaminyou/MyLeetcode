class Solution {
public:
    int totalMoney(int n) {
        int mod = n % 7;
        int quot = n / 7;
        return 28 * quot + 7 * max(quot * (quot - 1) / 2, 0) + (1 + mod + 2 * quot) * mod / 2;
    }
};
