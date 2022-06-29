class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> ori2new;
        int index = 0;
        for (auto& num : nums) {
            if (ori2new.find(num) == ori2new.end()) {
                ori2new[num] = index;
                index++;
            }
        }
        int unique = ori2new.size();
        vector<int> counts(unique, 0);
        for (auto& num : nums) {
            counts[ori2new[num]]++;
        }
        
        int m = quantity.size();
        // precompute requirement for each state
        vector<int> precomputed(1 << m, 0);
        for (int state = 0; state < (1 << m); ++state) {
            int count = 0;
            for (int i = 0; i < m; ++i) {
                if (state & (1 << i)) count += quantity[i];
            }
            precomputed[state] = count;
        }
        
        // dp[i][j]: i state can be satified by [1, j] items
        vector<vector<bool>> dp(1 << m, vector<bool>(unique + 1, false));
        dp[0][0] = true;
        for (int state = 0; state < (1 << m); ++state) {
            for (int i = 1; i <= unique; ++i) {
                dp[state][i] = dp[state][i - 1];
                for (int subset = state; subset; subset = (subset - 1) & state) {
                    // state -> subset + others (state ^ subset)
                    if (precomputed[subset] <= counts[i - 1] && dp[state ^ subset][i - 1]) {
                        dp[state][i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[(1 << m) - 1][unique];
    }
};