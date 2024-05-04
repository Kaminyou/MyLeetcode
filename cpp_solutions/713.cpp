class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int product = 1;
        int res = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            product *= nums[right];
            while (left <= right && product >= k) {
                product /= nums[left];
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};