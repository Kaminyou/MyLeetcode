class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> bits;
        int index = 0;
        while (n) {
            if (n & 1) bits.push_back(index);
            index++;
            n >>= 1;
        }
        vector<int> res;
        long long mod = 1e9 + 7;
        for (auto& query : queries) {
            long long ans = 1;
            for (int i = query[0]; i <= query[1]; ++i) {
                ans *= (1 << bits[i]);
                ans %= mod;
            }
            res.push_back((int)ans);
        }
        return res;
    }
};