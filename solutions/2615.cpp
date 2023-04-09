class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
        vector<long long> res(n, 0);
        for (auto& [num, positions] : mp) {
            if (positions.size() == 1) continue;
            int m = positions.size();
            long long cum = 0;
            for (int i = 1; i < m; ++i) {
                cum += positions[i] - positions[0];
            }
            res[positions[0]] = cum;
            for (int i = 1; i < m; ++i) {
                long long right = m - i;
                long long left = i;
                cum -= right * (positions[i] - positions[i - 1]);
                cum += left * (positions[i] - positions[i - 1]);
                res[positions[i]] = cum;
            }
        }
        return res;
    }
};