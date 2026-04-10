class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
        int res = INT_MAX;
        for (auto& [k, v] : mp) {
            if (v.size() < 3) continue;
            int m = v.size();
            for (int i = 0; i <= m - 3; ++i) {
                res = min(res, 2 * (v[i + 2] - v[i]));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
