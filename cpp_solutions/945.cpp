class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int criteria = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > criteria) {
                criteria = nums[i];
            }
            else {
                criteria++;
                res += criteria - nums[i];
            }
        }
        return res;
    }
};
