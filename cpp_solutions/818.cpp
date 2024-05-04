class Solution {
public:
    int dp(int target, vector<int>& memo) {
        if (target < 0) return INT_MAX;
        if (memo[target] != -1) return memo[target];
        int res = INT_MAX;
        
        int power = 0;
        while ((1 << power) - 1 < target) power++;
        // currently, use power step will be over
        // case: over one
        res = min(res, power + 1 + dp((1 << power) - 1 - target, memo));
        
        // case before
        int reverse = 0;
        while (reverse < power - 1) {
            int location = (1 << (power - 1)) - 1 - ((1 << reverse) - 1);
            res = min(res, power - 1 + 1 + reverse + 1 + dp(target - location, memo));
            reverse++;
        }
        return memo[target] = res;
    }
    int racecar(int target) {
        vector<int> memo(1 << 14, -1);
        for (int i = 0; i <= 14; ++i) {
            memo[(1 << i) - 1] = i;
        }
        return dp(target, memo);
    }
};