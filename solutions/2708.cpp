class Solution {
public:
    long long maxVaule = LLONG_MIN;
    void backtracking(vector<int>& nums, int index, long long current, bool useOne) {
        if (nums.size() == index) {
            if (useOne) maxVaule = max(maxVaule, current);
            return;
        }
        backtracking(nums, index + 1, current * nums[index], true);
        backtracking(nums, index + 1, current, useOne);
    }
    long long maxStrength(vector<int>& nums) {
        backtracking(nums, 0, 1, false);
        return maxVaule;
    }
};