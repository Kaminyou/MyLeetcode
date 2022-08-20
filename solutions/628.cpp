class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3) return nums[0] * nums[1] * nums[2];
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int chose1 = nums[0] * nums[1] * nums[n - 1];
        int chose2 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        return max(chose1, chose2);
    }
};
