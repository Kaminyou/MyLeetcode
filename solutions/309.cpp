class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int buy = -prices[0];
        int sell = 0;
        int cooldown = 0;
        for (int i = 1; i < n; i++) {
            int nextBuy = max(buy, cooldown - prices[i]);
            int nextSell = buy + prices[i];
            int nextCooldown = max(cooldown, sell);
            buy = nextBuy;
            sell = nextSell;
            cooldown = nextCooldown;
        }
        return max(sell, cooldown);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> bought(n, 0);
        vector<int> sold(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (i >= 2) {
                bought[i] = max({bought[i - 1], -prices[i], sold[i - 2] - prices[i]});
            }
            else if (i >= 1) {
                bought[i] = max({bought[i - 1], -prices[i]});
            }
            else bought[i] = -prices[i];
            if (i >= 1) {
                sold[i] = max(sold[i - 1], bought[i - 1] + prices[i]);
            }
            else sold[i] = 0;
        }
        return sold[n - 1];
    }
};