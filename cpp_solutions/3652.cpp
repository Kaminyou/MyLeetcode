class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long res = LLONG_MIN;
        int n = prices.size();
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += prices[i] * strategy[i];
        }
        res = max(res, sum);
        for (int i = 0; i < k / 2; ++i) {
            sum -= prices[i] * strategy[i];
            sum += prices[i] * 0;
        }
        for (int i = k / 2; i < k; ++i) {
            sum -= prices[i] * strategy[i];
            sum += prices[i] * 1;
        }
        res = max(res, sum);
        for (int i = k; i < n; ++i) {
            sum -= prices[i] * strategy[i];
            sum += prices[i] * 1;

            sum -= prices[i - k] * 0;
            sum += prices[i - k] * strategy[i - k];

            sum -= prices[i - k + k / 2] * 1;
            sum += prices[i - k + k / 2] * 0;

            res = max(res, sum);
        }
        return res;
    }
};

