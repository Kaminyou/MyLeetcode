class Solution {
public:
    int need2state(vector<int>& needs) {
        int state = 0;
        for (auto& need : needs) {
            state += need;
            state <<= 4;
        }
        return state;
    }
    unordered_map<int, int> memo;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = 0;
        int n = price.size();
        int state = need2state(needs);
        if (memo.find(state) != memo.end()) return memo[state];
        for (int i = 0; i < n; ++i) {
            res += price[i] * needs[i];
        }
        
        for (auto& order : special) {
            bool isValid = true;
            for (int i = 0; i < n; ++i) {
                if (order[i] > needs[i]) isValid = false;
            }
            
            if (isValid) {
                for (int i = 0; i < n; ++i) {
                    needs[i] -= order[i];
                }
                res = min(res, shoppingOffers(price, special, needs) + order.back());
                for (int i = 0; i < n; ++i) {
                    needs[i] += order[i];
                }
            }
        }
        return memo[state] = res;
    }
};