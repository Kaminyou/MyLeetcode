class Solution {
public:
    void backtracking(vector<int>& nums, int index, int cur, int target, int& res) {        
        if (index == nums.size()) {
            if (cur == target) res++;
            return;
        }
        backtracking(nums, index + 1, cur | nums[index], target, res);
        backtracking(nums, index + 1, cur, target, res);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for (auto& num : nums) target |= num;
        int res = 0;
        backtracking(nums, 0, 0, target, res);
        return res;
    }
};
