class Solution {
public:
    bool isVaildState(int state, int m) {
        vector<int> temp;
        for (int i = 0; i < m; ++i) {
            int bit = state % 3;
            if ((!temp.empty()) && (bit == temp.back())) return false;
            temp.push_back(bit);
            state /= 3;
        }
        return true;
    }
    bool isValidTransit(int state0, int state1, int m) {
        for (int i = 0; i < m; ++i) {
            if (state0 % 3 == state1 % 3) return false;
            state0 /= 3;
            state1 /= 3;
        }
        return true;
    }
    int colorTheGrid(int m, int n) {
        vector<int> candidates;
        long long mod = 1e9 + 7;
        for (int state = 0; state < pow(3, m); ++state) {
            if (isVaildState(state, m)) candidates.push_back(state);
        }

        vector<long long> dp(candidates.size(), 1);
        vector<long long> dpTemp(candidates.size(), 0);
        for (int i = 1; i < n; ++i) {
            for (int curStateIdx = 0; curStateIdx < candidates.size(); ++curStateIdx) {
                dpTemp[curStateIdx] = 0;
                for (int preStateIdx = 0; preStateIdx < candidates.size(); ++preStateIdx) { 
                    if (isValidTransit(candidates[preStateIdx], candidates[curStateIdx], m)) {
                        dpTemp[curStateIdx] += dp[preStateIdx];
                        dpTemp[curStateIdx] %= mod;
                    }
                }
            }
            swap(dp, dpTemp);
        }
        long long res = 0;
        for (auto& num : dp) {
            res += num;
            res %= mod;
        }
        return res;
    }
};
