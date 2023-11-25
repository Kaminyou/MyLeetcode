class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> res;
        int diff = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) diff += nums[i] - nums[0];
        res.push_back(diff);
        for (int i = 1; i < n; ++i) {
            diff -= (nums[i] - nums[i - 1]) * (n - i);
            diff += (nums[i] - nums[i - 1]) * i;
            res.push_back(diff);
        }
        return res;
    }
};
