class Solution {
public:
    int batch;
    int n;
    unordered_map<long long, int> memo;
    int dp(long long state, int cache, int curr) {
        if (curr == n) return 0;
        if (memo.find(state) != memo.end()) return memo[state];
        int res = 0;
        int bonus = (cache == 0);
        for (int i = 1; i < batch; ++i) {
            if ((state >> (i * 5)) % 32 == 0) continue;
            state -= 1ll << (i * 5);
            res = max(res, dp(state, (cache + i) % batch, curr + 1));
            state += 1ll << (i * 5);
        }
        return memo[state] = res + bonus;
    }
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        batch = batchSize;
        n = groups.size();
        vector<int> freq(batchSize, 0);
        for (auto& group : groups) {
            freq[group % batchSize]++;
        }
        long long state = 0;
        for (int i = 0; i < batchSize; ++i) {
            state += (long long)freq[i] << (i * 5);
        }
        return freq[0] + dp(state, 0, freq[0]);
    }
};