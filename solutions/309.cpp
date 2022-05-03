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