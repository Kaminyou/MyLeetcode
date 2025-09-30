class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                nums[j] = nums[j] + nums[j + 1];
                nums[j] %= 10;
            }
        }
        return nums[0];
    }
};

