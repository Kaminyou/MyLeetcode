class Solution {
    static const int MOD = 1e9 + 7;

public:
    int possibleStringCount(string word, int k) {
        if (word.empty()) return 0;

        vector<int> groups;
        int count = 1;
        for (size_t i = 1; i < word.size(); ++i) {
            if (word[i] == word[i - 1]) count++;
            else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);

        long long total = 1;
        for (int num : groups)
            total = (total * num) % MOD;

        if (k <= (int)groups.size()) return total;

        vector<int> dp(k, 0);
        dp[0] = 1;
        for (int num : groups) {
            vector<int> newDp(k, 0);
            long long sum = 0;
            for (int s = 0; s < k; ++s) {
                if (s > 0) sum = (sum + dp[s - 1]) % MOD;
                if (s > num) sum = (sum - dp[s - num - 1] + MOD) % MOD;
                newDp[s] = sum;
            }
            dp = newDp;
        }

        long long invalid = 0;
        for (int s = groups.size(); s < k; ++s)
            invalid = (invalid + dp[s]) % MOD;

        return (total - invalid + MOD) % MOD;
    }
};
