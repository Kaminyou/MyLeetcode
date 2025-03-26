class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        map<int, int> mp;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[grid[i][j]]++;
            }
        }
        int current = (*mp.begin()).first;
        int op = 0;
        vector<pair<int, int>> nums;
        vector<int> prefixSum(m * n + 1, 0);
        int index = 1;
        for (auto& [num, cnt] : mp) {
            int diff = num - current;
            if (diff % x != 0) return -1;
            op += diff / x * cnt;
            nums.push_back({num, cnt});
            prefixSum[index] = prefixSum[index - 1] + cnt;
            index++;
        }
        int res = op;
        int k = nums.size();
        for (int i = 1; i < k; ++i) {
            int diff = nums[i].first - nums[i - 1].first;
            op += diff / x * prefixSum[i];
            op -= diff / x * (prefixSum[k] - prefixSum[i]);
            res = min(op, res);
        }
        return res;
    }
};
