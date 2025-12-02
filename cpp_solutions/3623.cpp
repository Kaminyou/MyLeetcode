class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> y2cnt;
        for (auto& point : points) y2cnt[point[1]]++;
        vector<long long> cnts;
        vector<long long> prefixSum;
        prefixSum.push_back(0);
        long long sum = 0;
        long long mod = 1e9 + 7;
        for (auto& [p, v] : y2cnt) {
            if (v - 2 < 0) continue;
            long long comb = v * (v - 1) / 2;
            cnts.push_back(comb);
            sum += comb;
            sum %= mod;
            prefixSum.push_back(sum);
        }
        long long res = 0;
        int n = cnts.size();
        for (int i = 0; i < n - 1; ++i) {
            long long cur = cnts[i] * (prefixSum[n] - prefixSum[i + 1]);
            cur %= mod;
            res += cur;
            res %= mod;
        }
        return res;
    }
};

