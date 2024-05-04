class Solution {
public:
    vector<vector<int>> memo;
    int dp(int n, int state, int sum, vector<int>& tasks, int sessionTime) {
        if (state == 0) {
            memo[state][sum] = (sum > 0) ? 1 : 0;
            return memo[state][sum];
        }
        if (memo[state][sum] != -1) return memo[state][sum];
        
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if ((state & (1 << i)) == (1 << i)) {
                int nextSum = sum + tasks[i];     
                
                if (nextSum > sessionTime) {
                    nextSum = tasks[i];
                    res = min(res, 1 + dp(n, state ^ (1 << i), nextSum, tasks, sessionTime));
                }
                else if (nextSum == sessionTime) {
                    nextSum = 0;
                    res = min(res, 1 + dp(n, state ^ (1 << i), nextSum, tasks, sessionTime));
                }
                else {
                    res = min(res, dp(n, state ^ (1 << i), nextSum, tasks, sessionTime));
                }
                
            }
        }
        return memo[state][sum] = res;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int state = (1 << n) - 1;
        memo.resize((1 << n), vector<int>(sessionTime + 1, -1));
        
        return dp(n, state, 0, tasks, sessionTime);
    }
};