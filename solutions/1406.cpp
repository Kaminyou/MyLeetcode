class Solution {
public:
    int dp(vector<int>& stoneValue, int curr, vector<int>& memo) {
        if (curr >= stoneValue.size()) return 0;
        if (memo[curr] != INT_MIN) return memo[curr];
        int sum = 0;
        int res = INT_MIN;
        for (int i = curr; i < curr + 3 && i < stoneValue.size(); ++i) {
            sum += stoneValue[i];
            res = max(res, sum - dp(stoneValue, i + 1, memo));
        }
        return memo[curr] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> memo(stoneValue.size(), INT_MIN);
        int ans = dp(stoneValue, 0, memo);
        if (ans > 0) return "Alice";
        else if (ans < 0) return "Bob";
        else return "Tie";
    }
};