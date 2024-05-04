class Solution {
public:
    int countPalindromes(string s) {
        int state = 1;
        int mod = 1e9 + 7;
        vector<vector<int>> dp1(2, vector<int>(10, 0)); // i
        vector<vector<vector<int>>> dp2(2, vector<vector<int>>(10, vector<int>(10, 0))); // ij
        vector<vector<vector<int>>> dp3(2, vector<vector<int>>(10, vector<int>(10, 0))); // ijx
        vector<vector<vector<int>>> dp4(2, vector<vector<int>>(10, vector<int>(10, 0))); // ijxj
        
        int res = 0;
        for (auto& c : s) {
            int number = c - '0';
            for (int i = 0; i < 10; ++i) {
                dp1[state][i] = dp1[state ^ 1][i];
                if (number == i) dp1[state][i]++;
                dp1[state][i] %= mod;

                for (int j = 0; j < 10; ++j) {
                    dp2[state][i][j] = dp2[state ^ 1][i][j] + (number == j ? dp1[state ^ 1][i] : 0);
                    dp2[state][i][j] %= mod;
                    dp3[state][i][j] = dp3[state ^ 1][i][j] + dp2[state ^ 1][i][j];
                    dp3[state][i][j] %= mod;
                    dp4[state][i][j] = dp4[state ^ 1][i][j] + (number == j ? dp3[state ^ 1][i][j] : 0);
                    dp4[state][i][j] %= mod;
                    if (number == i) {
                        res += dp4[state ^ 1][i][j];
                        res %= mod;
                    }
                }
            }
            state ^= 1;
        }
        return res;
    }
};