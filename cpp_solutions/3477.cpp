class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = 0;
        int n = baskets.size();
        for (auto& fruit : fruits) {
            bool feasible = false;
            for (int i = 0; i < n; ++i) {
                if (baskets[i] >= fruit) {
                    baskets[i] = 0;
                    feasible = true;
                    break;
                }
            }
            if (!feasible) res++;
        }
        return res;
    }
};
