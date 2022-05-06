class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) res.push_back(i);
        }
        return res;
    }
};