class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = INT_MAX;
        int currRes = INT_MIN;
        for (auto price : prices) {
            currMin = min(currMin, price);
            currRes = max(currRes, price - currMin);
        }
        return currRes;
    }
};