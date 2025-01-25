class Solution {
public:
    long long mod = 1e9 + 7;
    long long inv(long long a) {
        if (a == 1) return 1;
        return (mod - mod / a) * inv(mod % a) % mod;
    }
    vector<vector<int>> combineTable(int n, int k) {
        vector<vector<int>> table(n + 1, vector<int>(k + 1, -1));
        for (int i = 1; i <= n; ++i) {
            long long res = 1L;
            for (int j = 0; j < k; ++j) {
                res = res * (i - j) % mod;
                res = res * inv(j + 1) % mod;
                table[i][j + 1] = (int)res;
            } 
        }
        return table;
    }
    int minMaxSums(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        vector<vector<int>> table = combineTable(n, k);
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < n; ++j) {
                long long current = nums[j];
                if (j > 0 && i - 1 > 0) {
                    long long left = table[j][i - 1];
                    res += left * current;
                }
                else if (i == 1){
                    res += current;
                }
                if (n - j - 1 > 0 && i - 1 > 0) {
                    long long right = table[n - j - 1][i - 1];
                    res += right * current;
                }
                else if (i == 1){
                    res += current;
                }
                res %= mod;
            }
        }
        return res;
    }
};
