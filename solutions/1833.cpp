class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        for (auto& cost : costs) {
            if (coins >= cost) {
                coins -= cost;
                cnt++;
            }
            else break;
        }
        return cnt;
    }
};