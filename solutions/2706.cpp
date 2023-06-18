class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int left = money - prices[0] - prices[1];
        if (left < 0) return money;
        return left;
    }
};