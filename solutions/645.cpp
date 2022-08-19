class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]) - 1;
            if (nums[num] < 0) res.push_back(num + 1);
            nums[num] = -abs(nums[num]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};
