class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> positions;
        int n = corridor.size();
        for (int i = 0; i < n; ++i) {
            if (corridor[i] == 'S') positions.push_back(i);
        }
        int m = positions.size();
        if (m == 0) return 0;
        if (m & 1) return 0;
        long long res = 1;
        long long mod = 1e9 + 7;
        for (int i = 1; i < m - 1; i += 2) {
            res *= (positions[i + 1] - positions[i]);
            res %= mod;
        }
        return res;
    }
};
