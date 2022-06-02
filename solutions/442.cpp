class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int currNum = abs(nums[i]);
            if (nums[currNum - 1] < 0) res.push_back(currNum);
            else nums[currNum - 1] = -nums[currNum - 1];
        }
        return res;
    }
};