class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        int minVal = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] > minVal) {
                res = max(res, nums[i] - minVal);
            }
            minVal = min(minVal, nums[i]);
        }
        return res;
    }
};
