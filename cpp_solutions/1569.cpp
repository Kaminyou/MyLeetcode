class Solution {
public:
    vector<vector<long long>> table;
    int mod = 1e9 + 7;
    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;
        vector<int> left;
        vector<int> right;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[0]) right.push_back(nums[i]);
            else left.push_back(nums[i]);
        }
        long long leftNum = dfs(left) % mod;
        long long rightNum = dfs(right) % mod;
        int leftSize = left.size();
        return (((table[n - 1][leftSize] * leftNum) % mod) * rightNum) % mod;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            table[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        return (dfs(nums) - 1) % mod;
    }
};