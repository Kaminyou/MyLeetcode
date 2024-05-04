class Solution {
public:
    vector<vector<int>> res;
    void backtracking(int cnt, vector<int>& nums, vector<bool>& flags, vector<int>& current) {
        if (cnt == nums.size()) {
            res.push_back(current);
        }
        else {
            for (int i = 0; i < nums.size(); ++i) {
                if (flags[i]) continue;
                flags[i] = true;
                current.push_back(nums[i]);
                backtracking(cnt + 1, nums, flags, current);
                flags[i] = false;
                current.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> current;
        vector<bool> flags(n, false);
        backtracking(0, nums, flags, current);
        return res;
    }
};