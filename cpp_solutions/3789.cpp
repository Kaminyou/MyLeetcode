class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (need1 > need2) {
            swap(need1, need2);
            swap(cost1, cost2);
        }
        int maxNeed = max(need1, need2);
        long long res = LLONG_MAX;
        vector<int> tries = {0, need1, need1 + 1, need2};
        for (int c : tries) {
            int a = max(0, need1 - c);
            int b = max(0, need2 - c);
            long long cost = a * (long long)cost1 + b * (long long)cost2 + c * (long long)costBoth;
            res = min(res, cost);
        }
        return res;
    }
};

