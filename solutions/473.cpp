class Solution {
public:
    unordered_map<int, bool> memo;
    bool backtracking(vector<int>& matchsticks, int state, long long current, long long target) {
        if (state == 0 && current == target) return true;
        else if (state == 0) return false;
        else if (current > target) return false;
        if (memo.find(state) != memo.end()) return memo[state];
        if (current == target) current = 0;
        for (int i = 0; i < matchsticks.size(); ++i) {
            if ((state & (1 << i)) == (1 << i)) {
                if (backtracking(matchsticks, state ^ (1 << i), current + matchsticks[i], target)) {
                    return memo[state] = true;
                }
            }
        }
        return memo[state] = false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;
        long long sum = 0;
        for (auto& stick : matchsticks) sum += stick;
        if (sum % 4 != 0) return false;
        int state = (1 << n) - 1;
        long long target = sum / 4;
        return backtracking(matchsticks, state, 0, target);
    }
};