class Solution {
public:
    // time complexity: O(216 * N) => O(N)
    // space complexity: O(36 * N) => O(N)
    int distinctSequences(int n) {
        // edge case
        if (n == 1) return 6;
        
        const long long mod = 1e9 + 7;
        // define valid move: 0-indexed
        // e.g., 1 can move to {2, 3, 4, 5, 6} => valid[0] = {0,1,1,1,1,1}
        // e.g., 2 can move to {1, 3, 5} => valid[1] = {1,0,1,0,1,0}
        vector<vector<bool>> valid = {{0,1,1,1,1,1},{1,0,1,0,1,0},{1,1,0,1,1,0},{1,0,1,0,1,0},{1,1,1,1,0,1},{1,0,0,0,1,0}};
        
        // dp[l][i][j]: # of valid sequences if the length of sequence 
        //              is "l - 1"(0-indexed) and end with "j" considering previous one is "i"
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(6, vector<long long>(6, 0)));
        
        // initial state
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                dp[0][i][j] = 1;
            }
        }
        
        // length = 2 => not need to consider "at least a gap of 2 rolls between equal valued rolls."
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (valid[i][j]) dp[1][i][j] += dp[0][i][j];
            }
        }
        
        // length = [3, n] => need to consider "at least a gap of 2 rolls between equal valued rolls."
        for (int k = 2; k < n; ++k) {
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                    if (valid[i][j]) {
                        // a move (t->i->j) is valid only when valid[t][i] && valid[i][j] && (t != j)
                        for (int t = 0; t < 6; ++t) {
                            if (valid[t][i] && t != j) dp[k][i][j] += dp[k - 1][t][i];
                        }
                        dp[k][i][j] %= mod;
                    }
                }
            }
        }
        
        // sum up the last state, which is the answer
        // dp[n - 1][*][*]
        long long res = 0;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (valid[i][j]) {
                    res += dp[n - 1][i][j];
                    res %= mod;
                }
            }
        }
        return (int)res;
    }
};