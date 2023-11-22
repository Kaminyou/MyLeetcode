class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        int maxIndex = 0;
        int m = nums.size();
        for (int i = 0; i < m; ++i) {
            int n = nums[i].size();
            for (int j = 0; j < n; ++j) {
                mp[i + j].push_back(nums[i][j]);
                maxIndex = max(maxIndex, i + j);
            }
        }
        vector<int> res;
        for (int k = 0; k <= maxIndex; ++k) {
            int n = mp[k].size();
            for (int i = n - 1; i >= 0; --i) {
                res.push_back(mp[k][i]);
            }
        }
        return res;
    }
};
