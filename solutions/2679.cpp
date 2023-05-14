class Solution {
public:
    static bool compare(const int a, const int b) {
        return a > b;
    }
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        for (int i = 0; i < m; ++i) {
            sort(nums[i].begin(), nums[i].end(), compare);
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int maxValue = INT_MIN;
            for (int j = 0; j < m; ++j) {
                maxValue = max(maxValue, nums[j][i]);
            }
            res += maxValue;
        }
        return res;
    }
};