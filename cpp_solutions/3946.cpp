class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;
        for (int i = 0; i < n; ++i) {
            minPrice = min(minPrice, items[i][1]);
        }
        vector<int> counts(n, 1);
        for (int i = 0; i < n; ++i) {
            int factor = items[i][0];
            for (int j = 0; j < n; ++j) {
                if (i != j && (items[j][0] % factor == 0)) counts[i]++;
            }
        }

        vector<int> dp(budget + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int count = counts[i];
            for (int j = budget; j - price >= 0; --j) {
                if (dp[j - price] != -1) dp[j] = max(dp[j], dp[j - price] + count);
            }
        }

        int res = 0;
        for (int i = 0; i <= budget; ++i) {
            int remaining = budget - i;
            int extra = remaining / minPrice;
            res = max(res, dp[i] + extra);
        }
        return res;
    }
};

