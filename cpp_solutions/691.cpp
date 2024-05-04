class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        // use bit state to represent target
        // dp[state] = min # of sticker needed
        // 011000 => have h and e
        // thehat
        
        int m = 1 << n;
        vector<int> dp(m, INT_MAX);
        dp[0] = 0;
        
        for (int state = 0; state < m; ++state) {
            if (dp[state] == INT_MAX) continue;
            // construct the next state
            for (auto& sticker : stickers) {
                int nextState = state;
                for (auto c : sticker) {
                    for (int i = 0; i < n; ++i) {
                        if (c == target[i] && !((nextState >> i) & 1)) {
                            nextState |= (1 << i);
                            break;
                        }
                    }
                }
                dp[nextState] = min(dp[nextState], dp[state] + 1);
            }
        }
        return (dp[m - 1] == INT_MAX) ? -1 : dp[m - 1];
    }
};