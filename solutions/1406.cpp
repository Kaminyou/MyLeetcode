class Solution {
public:
    int dp(int curr, vector<int>& stoneValue, vector<int>& memo) {
        if (curr >= stoneValue.size()) return 0;
        if (memo[curr] != INT_MIN) return memo[curr];
        
        for (int i = 0, sum = 0; curr + i < stoneValue.size() && i < 3; i++) {
            sum += stoneValue[curr + i];
            memo[curr] = max(memo[curr], sum - dp(curr + i + 1, stoneValue, memo));
        }
        return memo[curr];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int sum = 0;
        for (auto value : stoneValue) sum += value;
        vector<int> memo(n, INT_MIN);
        int alice = dp(0, stoneValue, memo);
        if (alice == 0) return "Tie";
        else if (alice > 0) return "Alice";
        else return "Bob";
    }
};