class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 2) return -1;
        return nums[1];
    }
};