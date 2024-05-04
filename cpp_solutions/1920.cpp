class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int origin = nums[i] % n;
            int ans = nums[origin] % n;
            nums[i] += ans * n;
        }
        for (int i = 0; i < n; ++i) {
            nums[i] /= n;
        }
        return nums;
    }
};