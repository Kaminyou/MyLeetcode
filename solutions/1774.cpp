class Solution {
public:
    int difference = INT_MAX;
    int res = INT_MAX;
    void backtracking(vector<int>& toppingCosts, int current, int sum, int target) {
        if ((sum - target) > difference) return;
        if (current == toppingCosts.size()) {
            int currentDiff = abs(sum - target);
            if (currentDiff == difference) {
                res = min(res, sum);
            }
            else if (currentDiff < difference) {
                difference = currentDiff;
                res = sum;
            }
        }
        else {
            backtracking(toppingCosts, current + 1, sum, target);
            backtracking(toppingCosts, current + 1, sum + toppingCosts[current], target);
            backtracking(toppingCosts, current + 1, sum + toppingCosts[current] * 2, target);
        }
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        for (auto& baseCost : baseCosts) {
            backtracking(toppingCosts, 0, baseCost, target);
        }
        return res;
    }
};