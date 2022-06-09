class Solution {
public:
    int previousMissingNumber(vector<int>& nums, int index) {
        return nums[index] - nums[0] - index;
    }
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (previousMissingNumber(nums, mid) >= k) right = mid;
            else left = mid + 1;
        }
        if (left == n) return nums[n - 1] + k - previousMissingNumber(nums, n - 1);
        return nums[left] - (previousMissingNumber(nums, left) - k) - 1;
    }
};