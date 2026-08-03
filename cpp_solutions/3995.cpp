class Solution {
public:
    int dp(int index, string& source, string& target, vector<vector<string>>& rules, vector<int>& costs, vector<int>& memo) {
        if (index == source.size()) return 0;
        if (memo[index] != -1) return memo[index];
        int notTake = INT_MAX;
        if (source[index] == target[index]) {
            notTake = dp(index + 1, source, target, rules, costs, memo);
        }
        int take = INT_MAX;
        int m = rules.size();
        for (int i = 0; i < m; ++i) {
            string pattern = rules[i][0];
            string replacement = rules[i][1];
            int wild = 0;
            int k = pattern.size();
            if (index + k > source.size()) continue;
            bool flag = true;
            for (int j = 0; j < k; ++j) {
                if (target[index + j] != replacement[j]) {
                    flag = false;
                    break;
                }
                if (pattern[j] != '*' && source[index + j] != pattern[j]) {
                    flag = false;
                    break;
                }
                if (pattern[j] == '*') wild++;
            }
            if (flag) {
                int val = dp(index + k, source, target, rules, costs, memo);
                if (val != INT_MAX) take = min(take, val + costs[i] + wild);
            }
        }
        return memo[index] = min(notTake, take);
    }
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.size();
        vector<int> memo(n, -1);
        int val = dp(0, source, target, rules, costs, memo);
        return (val == INT_MAX) ? -1 : val;
    }
};
