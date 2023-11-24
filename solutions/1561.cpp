class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int m = n / 3;
        sort(piles.begin(), piles.end());
        int res = 0;
        for (int i = 0; i < m; ++i) {
            res += piles[n - 2 - i * 2];
        }
        return res;
    }
};
