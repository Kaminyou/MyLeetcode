class Solution {
public:
    bool dp(int maxChoosableInteger, int desiredTotal, int state, vector<char>& memo) {
        if (desiredTotal <= 0) return false;
        if (memo[state]) return memo[state] == 1;
        for (int num = 0; num < maxChoosableInteger; ++num) {
            if (state & (1 << num)) continue;
            if (!dp(maxChoosableInteger, desiredTotal - num - 1, state | (1 << num), memo)) {
                memo[state] = 1;
                return true;
                
            }
        }
        memo[state] = -1;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        vector<char> memo(1 << maxChoosableInteger, 0);
        return dp(maxChoosableInteger, desiredTotal, 0, memo);
    }
};