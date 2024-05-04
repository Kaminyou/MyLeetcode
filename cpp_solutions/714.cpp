class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -prices[0];
        int notHold = 0;
        for (int i = 1; i < n; i++) {
            int currHold = max(hold, notHold - prices[i]);
            int currNotHold = max(notHold, hold + prices[i] - fee);
            hold = currHold;
            notHold = currNotHold;
        }
        return notHold;
    }
};