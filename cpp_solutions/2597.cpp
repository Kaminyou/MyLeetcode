class Solution {
public:
    int backtracking(int index, int mask, vector<int>& nums, int k) {
        if (index == nums.size()) return mask > 0;
        int skip = backtracking(index + 1, mask, nums, k);
        
        bool canUse = true;
        for (int i = 0; i < index; ++i) {
            if (mask & (1 << i) && abs(nums[i] - nums[index]) == k) canUse = false;
        }
        if (canUse) return skip + backtracking(index + 1, mask | (1 << index), nums, k);
        return skip;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        return backtracking(0, 0, nums, k);
    }
};